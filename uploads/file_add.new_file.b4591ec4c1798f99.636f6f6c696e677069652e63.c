#include<stdio.h>
//#include<malloc.h>
int main()
{	int t,n,i,count,j;
	scanf("%d",&t);
	while(t!=0)
	{	count=0;
		scanf("%d",&n);
		int a[n],b[n];
		//int *a,*b;
		//a=(int *)malloc(n*sizeof(int));
		//b=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{scanf("%d",&a[i]);}
		for(j=0;j<n;j++);
		{scanf("%d",&b[j]);}
		for(i=0;i<n;i++)
		{  for(j=0;j<n;j++)
			{ if(b[j]>=a[i])
				{	count++;
					break;
				}
			}
		}
		printf("%d\n",count);
		t--;
	}
return 0;
}
