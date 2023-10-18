#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char num[1000]; int numCnt[10];
    memset(&num, '\0', 1000);
    memset(&numCnt, 0, 40);
    scanf("%s", num);
    int len = strlen(num);
    for(int i = 0; i <= len; i++)
    {
      switch (num[i]) {
      case '0':
        numCnt[0] = numCnt[0] + 1;
        break;
      case '1':
        numCnt[1] = numCnt[1] + 1;
        break;
      case '2':
        numCnt[2] = numCnt[2] + 1;
        break;
      case '3':
        numCnt[3] = numCnt[3] + 1;
        break;
      case '4':
        numCnt[4] = numCnt[4] + 1;
        break;
      case '5':
        numCnt[5] = numCnt[5] + 1;
        break;
      case '6':
        numCnt[6] = numCnt[6] + 1;
        break;
      case '7':
        numCnt[7] = numCnt[7] + 1;
        break;
      case '8':
        numCnt[8] = numCnt[8] + 1;
        break;
      case '9':
        numCnt[9] = numCnt[9] + 1;
        break;
      default:
          break;
      }
    }
    
    for (int i = 0; i < 10; i++)
    {
      printf("%d ", numCnt[i]);
    }
    printf("\n");
    return 0;
}
