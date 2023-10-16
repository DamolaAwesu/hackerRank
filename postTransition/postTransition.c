#include "postTransition.h"


void print_all_packages(Town t)
{
  printf("%s:\n",t.name);
  for(int i = 0; i < t.offices_count; i++)
  {
    printf("\t%d:\n",i);
    for(int j = 0; j < t.offices[i].packages_count; j++)
    {
        printf("\t\t%s\n",t.offices[i].packages[j].id);
    }
  }
}

void send_all_acceptable_packages(Town* source, int source_office_index, Town* target, int target_office_index)
{
  int count = 0;
  if((source != NULL)&&(target != NULL))
  {
    if((source_office_index < source->offices_count) && (source->offices_count > 0))
    {
      if((target_office_index < target->offices_count) && (target->offices_count > 0))
      {
        /** reallocate package memory for target and add the new package from source */
        target->offices[target_office_index].packages = (Package *)realloc(target->offices[target_office_index].packages,
                                                        ((sizeof (Package)*(target->offices[target_office_index].packages_count))
                                                        + (sizeof (Package)*(source->offices[source_office_index].packages_count))));

        /** check if package meets requirements and send */
        for(int i = 0; i < source->offices[source_office_index].packages_count; i-=count)
        {
          if((source->offices[source_office_index].packages[i].weight <= target->offices[target_office_index].max_weight) && (source->offices[source_office_index].packages[i].weight >= target->offices[target_office_index].min_weight))
          {
            /** add package to target and increment target package count */
            *(target->offices[target_office_index].packages + (target->offices[target_office_index].packages_count)) = (source->offices[source_office_index].packages[i]);
            target->offices[target_office_index].packages_count++;
            /** remove sent package from source package list */
            for(int j = i; j < (source->offices[source_office_index].packages_count); j++)
            {
              source->offices[source_office_index].packages[j] = source->offices[source_office_index].packages[j+1];
            }
            /** decrement source package count */
            source->offices[source_office_index].packages_count--;
            count = 1;
          }
          else
            count = 0;
          i++;
        }
        /** reallocate source package memory and free old package from source */
        source->offices[source_office_index].packages = (Package *)realloc(source->offices[source_office_index].packages, (sizeof (Package)*(source->offices[source_office_index].packages_count)));
        /** reallocate package memory for target and add the new package from source */
        target->offices[target_office_index].packages = (Package *)realloc(target->offices[target_office_index].packages, (sizeof (Package)*(target->offices[target_office_index].packages_count)));
      }
    }
  }
}

Town town_with_most_packages(Town* towns, int towns_count)
{
  int count = 0;
  Town * townT;

  if((towns != NULL) && (towns_count > 0))
  {
    for(int i = 0; i < towns_count; i++)
    {
      int packageCount = 0;
      for(int j = 0; j < (towns + i)->offices_count; j++)
      {
        packageCount += ((towns + i)->offices[j].packages_count);
      }
      if(packageCount > count)
      {
        count = packageCount;
        townT = towns + i;
      }
    }
  }

  return *townT;
}

Town* find_town(Town* towns, int towns_count, char* name)
{
  Town * result = (Town *)malloc(sizeof(Town));

  for(int i = 0; i < towns_count; i++)
  {
    if(strcmp((*(towns + i)).name,name) == 0)
    {
      result = (towns + i);
      break;
    }
  }
  return result;
}
