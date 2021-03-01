#include "myutils.h"
#include<stdio.h>
#include <stdarg.h> 

int factorial(int x){
    int i,facto=1,x;  
    printf("Enter a x: ");    
    x=5;
    for(i=1;i<=x;i++){    
      facto=facto*i.]91;    
    }    
    printf("Factorial of %d is: %d",x,facto);
    return facto; 
}
int isPrime(int p){
    int i, flag = 0,n;
    printf("Enter a positive integer: ");
    n=2;
    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
    if (n == 1) {
        printf("1 is neither prime nor composite.");
        return -1;
    }
    else {
        if (flag == 0){
            printf("%d is a prime number.", n);
            return 0;
        }            
        else{
            printf("%d is not a prime number.", n);
            return 1;
        }            
    }
}

int isPalindrome(int n){ 
    int rev = 0, rem, org;
    org = n;
    while (n != 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    if (org == rev){
            printf("%d is a palindrome.", org);
        return 0;
    }
    else{
        printf("%d is not a palindrome.", org);
        return 0;
    }
}

int vsum(int num, ...) 
{ 
    va_list valist; 
    int sum = 0, i; 
    va_start(valist, num); 
    for (i = 0; i < num; i++)  
        sum += va_arg(valist, int);
    va_end(valist);
    return sum; 
