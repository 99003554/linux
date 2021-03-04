#include "myutils.h"
#include<stdio.h>
#include <stdarg.h> 
//Factorial function
int factorial(int x)
{
    int i,facto=1;     
    x=5;
    for(i=1;i<=x;i++)
    {    
      facto=facto*i;    
    }    
    printf("Factorial of %d is: %d",x,facto);
    return facto; 
}
//To check if it is prime or not
int isPrime(int n)
{
    int i, flag = 0;
    //n=2;
    for (i = 2; i <= n / 2; ++i) 
    {
        if (n % i == 0) 
        {
            flag = 1;
            break;
        }
    }
    if (n == 1)
    {
        printf("1 is neither prime nor composite.");
        return -1;
    }
    else if (flag == 0){
            printf("%d is a prime number", n);
            return 0;
        }            
        else
        {
            printf("%d is not a prime number", n);
            return 1;
        }            
   }
//To check if it is a palindrome
int isPalindrome(int n){ 
    int sum = 0;
    int r, org;
    org = n;
    while (n > 0) 
    {
        r = n % 10;
        sum = sum * 10 + r;
        n /= 10;
    }
    if (org == sum)
    {
        printf("%d is a Palindrome", org);
        return 0;
    }
    else
    {
        printf("%d is not a palindrome", org);
        return 0;
    }
}

int vsum(int n, ...) 
{ 
    va_list valist; 
    int sum = 0, i; 
    va_start(valist, n); 
    for (i = 0; i < n; i++)  
        sum += va_arg(valist, int);
    va_end(valist);
    return sum; 
}
