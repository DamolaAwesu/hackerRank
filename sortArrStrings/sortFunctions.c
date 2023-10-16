#include "sortFunctions.h"

/** \brief  Check if string a is lexicographically less than string b
 *
 * \param   a - First string
 * \param   b - Second string
 * \return  0 - a is less than b; 1 - a is greater than b
 *
 */
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

/** \brief  Check if string a is lexicographically greater than string b
 *
 * \param   a - First string
 * \param   b - Second string
 * \return  0 - a is greater than b; 1 - a is less than b
 *
 */
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

/** \brief  Check if string a has less distinct characters than string b
 *
 * \param   a - First string
 * \param   b - Second string
 * \return  0 - a has same unique chars as b and a is lexicographically smaller than b; 1 - a has more unique characters than b
 *
 */
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

/** \brief  Check if string a is shorter than string b
 *
 * \param   a - First string
 * \param   b - Second string
 * \return  0 - a is same length as b and a is lexicographically smaller than b; 1 - a is longer than b
 *
 */
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
