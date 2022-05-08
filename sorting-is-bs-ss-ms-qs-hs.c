#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void bs(int *a,int n)
{
    int i,j,flag,temp;
    for(i=0;i<n-1;i++)
    {
        flag=1;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
        }
        if(flag)
            break;
    }
}
void is(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>temp)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=temp;
    }
}
void ss(int *a,int n)
{
    int i,j,min;
    for(int i=0;i<n-1;i++)
    {
        min=i+1;
        for(j=i+2;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        if(a[min]<a[i])
            swap(&a[min],&a[i]);
    }
}
int partition(int *a,int l,int u)
{
    int i,j,piv;
    i=l;
    j=u;
    piv=a[l];
    while(1)
    {
        while(a[i]<=piv&&i<=u)
        {
            i++;
        }
        while(a[j]>piv)
        {
            j--;
        }
        if(i<j)
            swap(&a[i],&a[j]);
        else 
            break;
    }
    swap(&a[l],&
    a[j]);
    return u;
}
void qs(int *a,int l,int u)
{
    if(l<u)
    {
        int p=partition(a,l,u);
        qs(a,l,p-1);
        qs(a,p+1,u);
    }
}
void merge(int *a,int l,int m,int u)
{
    int i,j,k=0;
    i=l;
    j=m+1;
    int *out=malloc((u-l+1)*sizeof(int));
    while(i<=m&&j<=u)
    {
        if(a[i]<a[j])
            out[k++]=a[i++];
        else
            out[k++]=a[j++];
    }
    while(i<=m)
    {
        out[k++]=a[i++];
    }
    while(j<=u)
    {
        out[k++]=a[j++];
    }
    for(int x=0;x<k;x++)
        a[l+x]=out[x];
}
void ms(int *a,int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        ms(a,l,m);
        ms(a,m+1,u);
        merge(a,l,m,u);
    }
}
void heapify(int *a,int i,int n)
{
    int lc=(2*i)+1,rc=(2*i)+2,max=i;
    if(lc<n&&a[max]<a[lc])
        max=lc;
    if(rc<n&&a[max]<a[rc])
        max=rc;
    if(i!=max)
    {
        swap(&a[max],&a[i]);
        heapify(a,max,n);
    }
}
void hs(int *a,int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
        heapify(a,i,n);
    while(n>1)
    {
        swap(&a[0],&a[n-1]);
        n--;
        heapify(a,0,n);
    }
}
int main()
{
    int n,d;
    printf("Enter the size of array \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("1)BINARY \n2)INSERTION \n3)SELECTION \n4)MERGE \n5)QUICK \n6)HEAP \n");
    scanf("%d",&d);
    switch(d)
    {
        case 1:
        bs(a,n);
        printf("The sorting from binary is as follows \n");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        break;
        case 2:
        is(a,n);
        printf("The sorting from insertion is as follows \n");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        break;
        case 3:
        ss(a,n);
        printf("The sorting from selection is as follows \n");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        break;
        case 4:
        ms(a,0,n-1);
        printf("The sorting from merge is as follows \n");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        break;
        case 5:
        qs(a,0,n-1);
        printf("The sorting from quick is as follows \n");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        break;
        case 6:
        hs(a,n);
        printf("The sorting from heap is as follows \n");
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        break;
        default:
        break;
    }
    return 0;
}