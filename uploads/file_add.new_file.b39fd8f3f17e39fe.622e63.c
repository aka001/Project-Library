#include<stdio.h>
#include<math.h>
int main()
{
    int a[100][100],p,l,i,j,test,b,d,n,k;
    scanf("%d",&test);
    while(test--)
    {
	scanf("%d%d",&n,&k);
	d=(n-1)/2;
	l=d;
	p=pow(2,d);
	for(i=0;i<p;i++)
	{
	    	b=i;
		for(j=l-1;j>=0;j--)
		{
			a[i][j]=(b&1);
			b=b>>1;
		}
	}
	for(i=0;i<p;i++)
	{
	    for(j=0;j<l;j++)
	    {
		printf("%d ",a[i][j]);
	    }
	    printf("\n");
	}
    }
    return 0;
}
