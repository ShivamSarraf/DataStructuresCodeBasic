#include <stdio.h>
int bs(int *a,int l,int u,int v)
{
    int m;
    while(l<=u)
    {
        m=(l+u)/2;
        if(a[m]==v)
            return m;
        else if(v<a[m])
            u=m-1;
        else
            l=m+1;
    }
    return -1;
}
int ls(int *a,int n,int v)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==v)
            return i;
    }
    return -1;
}
int main()
{
    int n,d,key;
    printf("Enter the size of array \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the search key \n");
    scanf("%d",&key);
    d=bs(a,0,n-1,key);
    printf("Element found at %d through binary search \n",d);
    printf("Enter the search key \n");
    scanf("%d",&key);
    d=ls(a,n,key);
    printf("Element found at %d through linear search \n",d);
    return 0;
}