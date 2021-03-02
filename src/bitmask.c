#include "bitmask.h"
int set(int a,int b)
{
    return (a|(1<<(b-1)));
}
int clear(int a,int b)
{
    return (a&(1<<(b-1)));
}
int flip(int a,int b)
{
    return (a^(1<<(b-1)));
}