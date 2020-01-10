
/***************************************************************************/
/* Assignment 1 solution for student purchasing; not to be re-distributed  */
/*                                                                         */
/*                                                                         */
/*                                                                         */
/* October 5, 2019                                                         */

#include <stdio.h>
#include <string.h>

/* check the entire input string and return 1 if all characters are digits */
/* returns 0 if any non-digit is detected */

int is_all_digit(char *input, int inputlen) {
  for (int i=0; i<inputlen; i++) {
    if (input[i] < '0' || input[i] > '9') {
      return 0; //0 is read as false
    }
  }
  return 1; //1 is true
}

int max(int a, int b) {
  return (a > b) ? a : b; //ternary operator
  // they are of the form (condition) ? evaluated to true : evaluated to false
}

int min(int a, int b) {
  return (a < b) ? a : b;
}

void lcs(char *input1, char *input2, int len1, int len2, char *answer) {
  int array[len1+1][len2+1];

  //initialize row 0 and column 0 to all zeros
  for (int i=0; i<len2+1; i++) {
    array[0][i] = 0;
  }
  for (int j=0; j<len1+1; j++) {
    array[j][0] = 0;
  }
  
  for(int m=1; m<=len1; m++) {
    for(int n=1; n<=len2; n++) {
      if (input1[m-1] == input2[n-1]) {
	array[m][n] = array[m-1][n-1] +1;
      } else {
	array[m][n] = max(array[m-1][n], array[m][n-1]);
      }
    }
  }
  int len =array[len1][len2]; //length of longest subsequence
  int l=len;
  
  int m = len1;
  int n = len2;
  memcpy(&answer[l],"",1);
  while (l>0) {
    if (input1[m-1] == input2[n-1]) {
      answer[l-1] = (char)input1[m-1];
      l--;
      n--;
      m--;
    } else {
      if (array[m-1][n] > array[m][n-1]) {
	m--;
      } else {
	n--;
      }
    }
  }
  return;
}


int main() {

  char input1[1001];
  char input2[1001];
  int new_char =0;
  int i;
  printf("To compute an LCS,\n");

  //infinite loop will keep asking for first sequence until it passes the is_digit test
  while (1) {
    i=0;
    printf("enter the first sequence: ");
    while ((new_char =getchar()) != (int)'\n') {
      input1[i] = new_char;
      i++;
    }
    input1[i] = '\0';
    if (is_all_digit(input1, strlen(input1))) {
      break;
    } else {
      printf("Error, non-digit character detected!\n");
    }
  }
  
  while (1) {
    printf("enter the second sequence: ");
    i=0;
    while ((new_char =getchar()) != (int)'\n') {
      input2[i] = new_char;
      i++;
    }
    input2[i] = '\0';
    if (is_all_digit(input2, strlen(input2))) {
      break;
    } else {
      printf("Error, non-digit character detected!\n");
    }
  }


  int len1 = strlen(input1);
  int len2 = strlen(input2);
  
  printf("\n# Two input sequences (length = %d, %d) are:\n%s\n%s",len1, len2, input1, input2);

  //the longest lcs cannot be longer than the short input
  char answer[min(len1,len2)];
  
  lcs(input1, input2,len1,len2, answer);
  printf("\n# an LCS (length = %d) is:\n%s\n\n", (int)strlen(answer),answer);

  return 0;
}
