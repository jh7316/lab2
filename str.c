#include <stdio.h>
#include <assert.h>

#include "string.h"


// Return the length of the string pointed to by "s".
//
// Note: C standard library function strlen accomplishes
// exactly the same functionality as string_len. In this exercise,
// please do not use strlen. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strlen instead of string_len
int string_len(char *s)
{
  // TODO: Your code here.
  int c=0;
  //run loop until string ends 
    while(*s!='\0')
    {   
        //increase counter variable
        c++;
        *s++;
    }
    return c;

}

// Compare strings "s1" and "s2". It returns less than, equal to or great than zero 
// if "s1" is found to be less than, match, or larger than "s2" alphabetically.
// For example, string_cmp("aa", "aaa") should return a negative number
// and string_cmp("aa", "a0") should return a positive number
// Note that we use the ASCII values of characters as basis for comparison.
// As the ascii value of 'a' is greater than the ascii value of '0', 
// "aa" is considered to be greater than "a0".
//
// Note: C standard library function strcmp accomplishes
// exactly the same functionality as string_cmp. In this exercise,
// please do not use strcmp. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strcmp instead of string_cmp.
int string_cmp(char *s1, char *s2)
{
   // TODO: Your code here.
  while(*s1!='\0'||*s2!='\0'){
          //compare character of current position
          if(*s1>*s2) return 1;
           else if(*s1<*s2) return -1;
           else{
          //move onto the next position
          *s1++;*s2++;
          
          }
      
      

   }
   return 0;

}

// Convert integer x into hex format and store the resulting hex string to "str",
// e.g., if x=16, then str should be "00000010".
// If x=26, then str should be "0000001a";
// The resulting hex string should always have exactly 8 hex characters 
// followed by the null character.
// We assume the caller has allocated an array of at least 9 characters for "str", 
// Note: please do not use formatted output, such as sprintf
void int_to_hex(unsigned int x, char *str)
{
   // TODO: Your code here.
  //divide x by 16. store the quotient and remainder.
  int r=x%16;
  int q=x/16;
  int i=7;
  //store the remainder to str array from the right end.
  //if r<10, we store the number value of r, which is +48 value in ASCII table 
  //if r>=10, we store the alphabet, which is +87 value in ASCII
  if(r<10) str[i]=r+ 48;else str[i]=r + 87;
  //process continues until the quotient becomes 0
  while(q!=0){
      r=q%16;
      q=q/16;
      i--;if(r<10) str[i]=r+ 48;else str[i]=r + 87;
     
  }
  int j;
  for(j=0;j<i;j++){
      str[j]='0';
  }

}


