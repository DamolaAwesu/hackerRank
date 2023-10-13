#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int retVal = 0;
    
    if((NULL !=  a) && (NULL != b))
    {
        if(strcmp(a,b) > 0)
        {
            retVal = 1;
        }
    }
    return retVal;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int retVal = 0;
    
    if((NULL !=  a) && (NULL != b))
    {
        if(strcmp(a,b) < 0)
        {
            retVal = 1;
        }
    }
    return retVal;
}

static int countUniqueChars(const char * s) {
    int count = strlen(s); int len = strlen(s); int flag = 0;
    for(int i = 0; i < len; i++)
    {
        flag = 0;
        for(int j = i+1; j < len; j++)
        {
            if(s[i] == s[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            count--;
    }
    return count;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int retVal = 0; int uniqA = 0; int uniqB = 0;
    
    if((NULL !=  a) && (NULL != b))
    {
        //count unique characters in string
        uniqA = countUniqueChars(a);
        uniqB = countUniqueChars(b);
        if(uniqA > uniqB)
        {
            retVal = 1;
        }
        else if(uniqA == uniqB)
        {
            retVal = lexicographic_sort(a, b);
        }
    }
    return retVal;
}

int sort_by_length(const char* a, const char* b) {
    int retVal = 0;
    if((NULL != a) && (NULL != b))
    {
        if(strlen(a) > strlen(b))
        {            
            retVal = 1;
        }
        else if(strlen(a) == strlen(b))
        {
            retVal = lexicographic_sort(a, b);
        }
    }
    
    return retVal;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int retVal = 0;
    if(arr != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                retVal = cmp_func(arr[i],arr[j]);
                if(retVal == 1)
                {
                    char * tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
