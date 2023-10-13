#include <string.h>

extern int lexicographic_sort(const char* a, const char* b);
extern int lexicographic_sort_reverse(const char* a, const char* b);
extern int sort_by_number_of_distinct_characters(const char* a, const char* b);
extern int sort_by_length(const char* a, const char* b);
extern void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b));
