#include<stdio.h>
int a[100];
int main()
{
    int n,k,i,j,temp,len;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
	scanf("%d",&a[i]);
    }
    len=i;
    for(i=0;i<n;i++)
    {
	for(j=0;j<n;j++)
	{
	    if(a[i]>a[j])
		{
		    temp=a[i];
		    a[i]=a[j];
		    a[j]=temp;
		}
	}
    }

    if(k<len)
    {
	printf("%d %d\n",a[k-1],a[k-1]);
    }
    else
    {
	printf("-1\n");
    }
    return 0;
}
    



