#include<stdio.h>
#include<math.h>
int max(double x,double y)
{
	if(x>y)
		return x;
	return y;
}
int min(double x,double y)
{
	if(x<y)
		return x;
	return y;
}
int main()
{
	int i,j,k,x[200],y[200],t=0;
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d%d",&x[i],&y[i]);
		double dis[200][200],mi,ma;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				dis[i][j]=dis[j][i]=sqrt((pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2)));
			}
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					ma=max(dis[i][k],dis[k][j]);
					mi=min(dis[i][j],ma);
					dis[i][j]=mi;
				}
			}
		}
		printf("Scenario #%d\n",++t);
		printf("Frog Distance = 0.3f\n\n",dis[0][1]);
	}
	return 0;
}
			
