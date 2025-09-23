#include<stdio.h>
#include<string.h>
void myfunc(char a[])
{
    int i=0;
    for(i=0;i<strlen(a);i++)
    {
        printf("The address of %c=%p\n",a[i],&a[i]);
    }
}
int main()
{
    char str1[100];
    printf("Enter a word:");
    scanf("%s",str1);
    myfunc(str1);
    return 0;
}
