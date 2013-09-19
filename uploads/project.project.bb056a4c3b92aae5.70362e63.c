#include<stdio.h>
int a[10000][10000]={0};
int main()
{
    int t,k,m,count,s1,i,j,c,s2,fl;
    scanf("%d",&t);
    while(t--)
    {
	fl=0;
	scanf("%d %d",&k,&m);
	j=k;
	while(j!=0)
	{
	    scanf("%d %d",&s1,&s2);
	    if(s1==1 && s2==k)
	    {
		fl=1;
	    }
	    else
	    {
		a[s1][s2]=1;
	    }
	    j--;
	}
	c=0;
	int f=0;
	for(i=1;i<=k;i++)
	{
	    count=0;
	    for(j=1;j<=k;j++)
		{
			if(a[i][j]==1)
			{
			    count++;
			}
			if(j==k)
			{
			  if(a[i][j]==1)
			  {
			      f++;
			  }
			}
		}
	    if(count>1)
	    {
		c=c+count-1;
	    }
	}
	if(f==0)
	{
		printf("-1\n");
	}
	else if(fl==1)
	{
	    printf("0\n");
	}
	else
	{
	    printf("%d\n",c);
	}
    }
    return 0;
}
