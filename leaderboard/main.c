#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);


int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count)
{
  int oldLeadRank[ranked_count]; int nxtRank = 1;
  int * playerRank = (int *)malloc(sizeof(int)*player_count);

  oldLeadRank[0] = 1;
  /** rank old leaderboard */
  for(int i = 1; i < ranked_count; i++)
  {
    if(ranked[i] < ranked[i - 1])
    {
      oldLeadRank[i] = ++nxtRank;
    }
    else {
      oldLeadRank[i] = nxtRank;
    }
  }

  /*
  * Traverse the old leaderboard in reverse order to find rank of current score
  * (traversed in correct order)
  * ranked_count is incremented on every rank update to ensure the current position
  * in the old leaderboard is checked on the next iteration
  */
  for(int i = 0; i < player_count; i++)
  {
    for (int j = ranked_count - 1; j >= 0; j--)
    {
      if(player[i] < ranked[j])
      {
        playerRank[i] = oldLeadRank[j] + 1;
        ranked_count = j + 1;
        break;
      }
      else if(player[i] == ranked[j])
      {
        playerRank[i] = oldLeadRank[j];
        ranked_count = j + 1;
        break;
      }
      else if((player[i] > ranked[j]) && (j == 0))
      {
        playerRank[i] = oldLeadRank[j];
        ranked_count = j + 1;
        break;
      }
    }
  }
  *result_count = player_count;

  return playerRank;
}

int main()
{
  int ranked_count = parse_int(ltrim(rtrim(readline())));

  char** ranked_temp = split_string(rtrim(readline()));

  int* ranked = malloc(ranked_count * sizeof(int));

  for (int i = 0; i < ranked_count; i++)
  {
    int ranked_item = parse_int(*(ranked_temp + i));

    *(ranked + i) = ranked_item;
  }

  int player_count = parse_int(ltrim(rtrim(readline())));

  char** player_temp = split_string(rtrim(readline()));

  int* player = malloc(player_count * sizeof(int));

  for (int i = 0; i < player_count; i++)
  {
    int player_item = parse_int(*(player_temp + i));

    *(player + i) = player_item;
  }

  int result_count;
  int* result = climbingLeaderboard(ranked_count, ranked, player_count, player, &result_count);

  for (int i = 0; i < result_count; i++)
  {
    fprintf(stdout, "%d", *(result + i));

    if (i != result_count - 1)
    {
      fprintf(stdout, "\n");
    }
  }

  fprintf(stdout, "\n");

  return 0;
}

char* readline()
{
  size_t alloc_length = 1024;
  size_t data_length = 0;

  char* data = malloc(alloc_length);

  while (true)
  {
    char* cursor = data + data_length;
    char* line = fgets(cursor, alloc_length - data_length, stdin);

    if (!line)
      break;

    data_length += strlen(cursor);

    if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
      break;

    alloc_length <<= 1;

    data = realloc(data, alloc_length);

    if (!data)
    {
      data = '\0';
      break;
    }
  }

  if (data[data_length - 1] == '\n')
  {
    data[data_length - 1] = '\0';

    data = realloc(data, data_length);

    if (!data)
      data = '\0';
  }
  else
  {
    data = realloc(data, data_length + 1);

    if (!data)
      data = '\0';
    else
      data[data_length] = '\0';
  }

  return data;
}

char* ltrim(char* str)
{
  if (!str)
    return '\0';

  if (!*str)
    return str;

  while (*str != '\0' && isspace(*str))
  {
    str++;
  }

  return str;
}

char* rtrim(char* str)
{
  if (!str)
    return '\0';

  if (!*str)
    return str;

  char* end = str + strlen(str) - 1;

  while (end >= str && isspace(*end))
  {
    end--;
  }

  *(end + 1) = '\0';

  return str;
}

char** split_string(char* str)
{
  char** splits = NULL;
  char* token = strtok(str, " ");

  int spaces = 0;

  while (token)
  {
    splits = realloc(splits, sizeof(char*) * ++spaces);

    if (!splits)
      return splits;

    splits[spaces - 1] = token;

    token = strtok(NULL, " ");
  }

  return splits;
}

int parse_int(char* str)
{
  char* endptr;
  int value = strtol(str, &endptr, 10);

  if (endptr == str || *endptr != '\0')
    exit(EXIT_FAILURE);

  return value;
}
