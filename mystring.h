#ifndef __MYSTRING_H
#define __MYSTRING_H
// mystrlen, mystrcpy, mystrcat, mystrcmp  

char *substring(int i,int j,char *ch)
{
    int n,k=0;
    char *ch1;
    ch1=(char*)malloc((j-i+1)*1);
    n=j-i+1;

    while(k<n)
    {
        ch1[k]=ch[i];
        i++;k++;
    }

    return (char *)ch1;
}

#endif
