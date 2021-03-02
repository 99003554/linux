#include<stdio.h>

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
/*int mystrlen(char *a){
  char s[] = a;
  int i;
  for (i = 0; s[i] != '\0'; ++i);
  printf("Length: %d", i);
  return i;
}*/
int mystrlen(char *a){
  char s[] = a;
  int i;
  for (i = 0; s[i] != '\0'; ++i);
  printf("Length of the string: %d", i);
  return i;
}