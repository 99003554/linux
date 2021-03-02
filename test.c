#include "mystring.h"
#include "bitmask.h"
#include "myutils.h"
#include<stdio.h>
int main()
{
    char s1[]="module";
    char s2[]="program";
    char s3[]="linux";
    int len=mystrlen(s1);
    printf("%d\n",len);
    printf("%d\n",mystrcmp(s1,s2));
    mystrcpy(s1,s2);
    printf("%s\n",s1);
    mystrcat(s1,s3);
    printf("%s\n",s1);
    int b1=7;
    printf("%d\n",set(b1,4));
    printf("%d\n",clear(b1,5));
    printf("%d\n",flip(b1,6));
    printf(factorial(5));
	printf(isPrime(2));
    printf(isPalindrome(121));
	printf("Sum  = %d\n",vsum(20,10,30));
    printf("Sum  = %d\n",vsum(4,10,20,50,30));
    printf("Sum  = %d\n",vsum(6,10,25,3,50,45,55));
    return 0;
}