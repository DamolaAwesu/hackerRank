#ifndef POSTTRANSITION_H_INCLUDED
#define POSTTRANSITION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 6

typedef struct package
{
	char* id;
	int weight;
} Package;

typedef struct post_office
{
	int min_weight;
	int max_weight;
	Package* packages;
	int packages_count;
} PostOffice;

typedef struct town
{
	char* name;
	PostOffice* offices;
	int offices_count;
} Town;


/**< Function Prototypes */
extern void print_all_packages(Town t);
extern void send_all_acceptable_packages(Town* source, int source_office_index, Town* target, int target_office_index);
extern Town town_with_most_packages(Town* towns, int towns_count);
extern Town* find_town(Town* towns, int towns_count, char* name);

#endif // POSTTRANSITION_H_INCLUDED
