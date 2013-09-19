#include<stdio.h>
#include<math.h>

int main()
{
    int i,flag,test,a,b[200],sum,j=0,req;
    scanf("%d",&test);
    while(test--)
    {
	flag=0;
	j=2;
	req=0;
	sum=26;
	scanf("%d",&a);
	for(i=1;i<a;i++)
	{
	    req+=sum;
	    if(flag==0)
	    {
		flag=1;
	    }
	    if(i%2!=0)
	    {
		sum=sum+26;
	    }
	    else
	    {
		sum=pow(26,j)-26;
		j++;
	    }
	   // req+=sum;
	}
	//if(flag==1)
	//{
		printf("%d\n",req);
	//}
	//else
	//{
	  //  printf("26\n");
	//}
    }
    return 0;
}
