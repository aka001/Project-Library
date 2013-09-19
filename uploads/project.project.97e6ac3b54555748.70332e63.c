#include<stdio.h>
int b[100000];
int main()
{
	int test,n,a,j,i,k,count,flag,cnt,ct;
	scanf("%d",&test);
	while(test!=0)
	{
		i=0;
		count=0;
		flag=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&a);
			if(flag==0)
			{
				b[i]=a;
				i++;
				flag=1;
			}
			else
			{
				if(a>b[i-1])
				{	
					ct=1;
					while(a>b[i-1] && i>0)
					{
						ct++;
						i--;
					}
					count=count+(ct*(ct-1))/2;
					//count=count+(i*ct);
					b[i]=a;
					i+=1;
				}
				else
				{
					b[i]=a;
					i++;
				}
			}

			//printf("count -->  %d\n",count);
			for(j=0;j<i;j++)
			{
				printf("%d ",b[j]);
			}
			printf("\n");

			printf("count -->  %d\n",count);
			//for(j=0;j<i;j++)
			///count=count+i-1;
		}
		count=count+i;
		printf("%d\n",count);
		test--;
	}
	return 0;
}
