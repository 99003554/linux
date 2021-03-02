//system calls
#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
    FILE *f1, *f2; 
    char file[100], d; 
    printf("File read \n"); 
    scanf("%s", f); 
     // Open one file for reading 
    f1 = fopen(file, "r"); 
    if (f1 == NULL) 
    { 
        printf("not opening file %s \n", file); 
        exit(0); 
    } 
    printf("File write \n"); 
    scanf("%s", file); 
  //write contents
  f2 = fopen(file, "w"); 
    if (f2 == NULL) 
    { 
        printf("not opening file %s \n", file); 
        exit(0); 
    } 
    d = fgetc(f1); 
    while (d != EOF) 
    { 
        fputc(d, f2); 
        d = fgetc(f1); 
    } 
     printf("\nCopy to %s", file); 
     fclose(f1); 
    fclose(f2); 
    return 0; 
}
