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

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

char* encryption(char* s) {
  uint8_t row, col;
  uint32_t len = 0;
  char * encryptedString, *result;
  if(s != NULL)
  {
    row = floor(pow(strlen(s),0.5));
    col = ceil(pow(strlen(s),0.5));
    len = row*col;
    if(len <= strlen(s))
    {
      row += 1;
      len = row * col;
    }
    
    char letters[row][col];
    memset(letters,'\0',(row*col));
    
    encryptedString = malloc((row*col) + (col));
    result = encryptedString;
    
    for(int i = 0; (i < row) && (*s != '\0'); i++)
    {
      for(int j = 0; j < col; j++)
      {
        letters[i][j] = *s++;
      }
    }
    
    for(int i = 0; i < col; i++)
    {
      for(int j = 0; j < row; j++)
      {
        if(letters[j][i] == '\0')
          break;
        *encryptedString++ = letters[j][i];
      }
      *encryptedString++ = ' ';
    }
    *encryptedString = '\0';
    fprintf(stdout,"%s",result);
    
  }
  return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = encryption(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
