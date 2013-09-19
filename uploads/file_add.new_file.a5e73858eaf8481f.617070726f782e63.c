#include<stdio.h>
int main()
{
    int a[1000005];
    int test,i,j,r,inp,c=103993,b=33102;
    scanf("%d",&test);
    for(i=0;i<=1000003;i++)
    {
	a[i]=c/b;
	c=(c%b)*10;
    }
    while(test--)
    {
	scanf("%d",&inp);
	if(inp==0)
	{
	    printf("%d\n",3);
	}
	else
	{
    		printf("3.");
		for(i=1;i<=inp;i++)
		{
		    printf("%d",a[i]);
		}
		printf("\n");
	}
    }
    return 0;
}
