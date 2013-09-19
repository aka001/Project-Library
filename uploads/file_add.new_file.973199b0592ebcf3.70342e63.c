#include<stdio.h>
int main()
{
	int t;
	int in[100]={0},a[100][100]={0},n,m,u,v,i,j,start,next,ord[100];
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
			break;
		while(m--)
		{
			scanf("%d%d",&u,&v);
			a[u][v]=1;
			in[v]++;
		}
		for(i=1;i<=n;i++)
			if(in[i]==0)
			{
				start=i;
				break;
			}
		in[start]=-1;
		ord[0]=start;
		for(i=1;i<n;i++)
		{
			for(j=1;j<=n;j++)
				if(in[j]==0)
				{
					next=j;
					break;
				}
			for(j=1;j<=n;j++)
			{
				if(a[start][j]==1)
				{
					a[start][j]=0;
					in[j]--;
				}
			}
			in[start]=-1;
			in[next]=-1;
			start=next;
			ord[i]=start;
		}
		for(i=0;i<n;i++)
			printf("%d ",ord[i]);
		printf("\n");
	}
	return 0;
}
