#include<stdio.h>
void mergesort(int a[100],int l,int u);
void merge(int a[100],int l,int mid,int u);
int main()
{
    int a[100],i,n;
	printf("\nenter no.of elements into the array");
    scanf("%d",&n);
    printf("\nenter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("\nafter sorting");
    for(i=0;i<n;i++)
    {
        printf("%5d",a[i]);
    }
    return 0;
}
void merge(int a[100],int l,int mid,int u)
{
    int i=l,j=mid+1,k=0,c[100];
    while(i<=mid&&j<=u)
    {
        if(a[i]<a[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=a[j++];
        }
    }
    for(; i<=mid;i++)
    {
        c[k++]=a[i];
       
    }
    for(;j<=u;j++)
    {
        c[k++]=a[j];
    }
   
   for(i=l,j=0;i<=u;i++,j++)
    a[i]=c[j];
   
}
void mergesort(int a[100],int l,int u)
{
    int mid;
    if(l<u)
    {
        mid=(l+u)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,u);
        merge(a,l,mid,u);
    }
}
