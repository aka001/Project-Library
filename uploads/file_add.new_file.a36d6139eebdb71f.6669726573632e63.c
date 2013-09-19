#include<stdio.h>
int main()
{
    int test,n,m,c,i,j,a[100003],b[100009],count,mul,cnt,e,f,fl;
    scanf("%d",&test);
    while(test--)
    {
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
	    a[i]=0;
	    b[i]=0;
	}
	count=0;
	mul=1;
	for(i=0;i<m;i++)
	{
	    scanf("%d %d",&e,&f);
	    if(a[e]!=0)
	    {
		a[f]=count;
	    }
	    else if(a[f]!=0)
	    {
		a[e]=count;
	    }
	    else
	    {
		count++;
		a[e]=a[f]=count;
	    }
	}
	/*for(i=1;i<=n;i++)
	{
	    if(a[i]==0)
	    {
		c++;
	    }
	}*/
	for(i=1;i<=n;i++)
	{
	    b[a[i]]++;
	}
	for(i=1;i<=n;i++)
	{
	    if(b[i]!=0)
	    {
		mul=(mul*b[i])%1000000007;
	    }
	}
	printf("%d %d\n",count+b[0],mul);
    }
    return 0;
}

