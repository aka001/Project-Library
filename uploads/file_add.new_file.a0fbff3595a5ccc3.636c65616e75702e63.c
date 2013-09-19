#include<stdio.h>
#include<malloc.h>
int main()
{	int t,n,m,*c,i,*b,j,a;
	scanf("%d",&t);
	while(t!=0)
	{	scanf("%d%d",&n,&m);
		c=(int *)malloc(n*sizeof(int));
		b=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{	c[i]=i+1;}
		for(i=0;i<m;i++)
		{	scanf("%d",&a);
			for(j=0;j<n;j++)
			{if(a==c[j])
				{c[j]=0;}
			}
		}
		j=0;
		for(i=0;i<n;i++)
		{  if(c[i]!=0)
			{ b[j]=c[i];
				j++;
			}
		}
		for(i=0;i<j;i+=2)
		{printf("%d ",b[i]);}
		printf("\n");
		for(i=1;i<j;i+=2)
		{printf("%d ",b[i]);}
		printf("\n");
		t--;
	}
	return 0;
}


