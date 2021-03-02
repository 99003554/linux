#include<stdio.h>
#include "mystring.h"
#include "bitmask.h"
#include "myutils.h"

//#include MAX_SIZE 100
char *mystrcat(char* s1,char* s2){
  int len, j;
  len = 0;
  while (s1[len] != '\0') 
  {
    ++len;
  }
  for (j = 0; s2[j] != '\0'; ++j, ++len) 
  {
    s1[len] = s2[j];
  }
  s1[len] = '\0';
  printf("Concatenation: ");
  puts(s1);
  return (char*) s1;
}
char *mystrcpy(char *text1, char *text2){
  strcpy(text2, text1);
  printf("String1 = %s\n", text1);
  printf("String2 = %s\n", text2);
  return text2;
}
int mystrlen(char *a){
  char s[]=a;
  int i;
  for (i = 0; s[i] != '\0'; ++i);
  printf("Length: %d", i);
  return i;
}
int mystrcmp(char *a,char *b){
  int flag=0,i=0;  
  while(a[i]!='\0' &&b[i]!='\0')  {
    if(a[i]!=b[i])  
    {  
      flag=1;  
      break;  
    }  
    i++;    
  if(flag==0) { 
    return 0;  }
  else  {
    return 1;  }
}
}