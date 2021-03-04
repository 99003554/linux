//system calls
#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
    FILE *f1, *f2; 
    int  ch, words, lines;
    char file[100], d; 
    printf("File read \n"); 
    scanf("%s", file); 
     // Open one file for reading 
    f1 = fopen("a.txt", "r"); 
    if (f1 == NULL) 
    { 
        printf("not opening file %s \n", "a.txt"); 
        exit(0); 
    } 
    //printf("File write \n"); 
    //scanf("%s", file); 
  //write contents
  f2 = fopen("b.txt", "w"); 
    if (f2 == NULL) 
    { 
        printf("not opening file %s \n", "b.txt"); 
        exit(0); 
    } 
    d = fgetc(f1); 
    while (d != EOF) 
    { 
        fputc(d, f2); 
        d = fgetc(f1); 
        ch++;
        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;
        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
         /* Increment words and lines for last word */
        if (ch > 0)
        {
            words++;
            lines++;
        }
    } 
    printf("\nCopy to %s", file); 
    printf("\n");
    printf("Total characters = %d\n", ch);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);
    fclose(f1); 
    fclose(f2); 
    return 0; 
}
        
        
        
        
      