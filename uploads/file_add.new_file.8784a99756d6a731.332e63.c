#include<stdio.h>
long long int a[5000002],f[5000002];
int main()
{
    long long int test,i,j,n,top,b,count,temp;
    scanf("%lld",&test);
    while(test--)
    {
	//long long int f[1000000];
	for(i=0;i<5000001;i++)
	{
	    f[i]=1;
	}
	//printf("%d\n",f[5]);
	count=0;
	scanf("%lld",&n);
	i=-1;
	top=0;
	while(top<n)
	{
	    scanf("%lld",&b);
	    if(i==-1)
	    {
		i++;
		a[i]=b;
	    }
	    else 
	    {
		if(b>a[i])
		{
			while(a[i]<=b && i>=0)	
			{
				//i--;
			    	if(a[i]==b)
				{
				    f[i]+=1;
				    if(i!=0)
				    {
					count+=f[i];
					//count++;
				    }
				    else
				    {
					count=count+f[i]-1;
				    }
				  //  break;
				}
				else
				{
					count+=f[i];
				}
				a[i]=0,f[i]=1;
				i--;
			}
			if(i!=-1)
			{
			    count++;
			}
			i++;
			a[i]=b;
		}
		else if(b<a[i])
		{
		    if(i!=-1)
		    {
			count+=1;
		    }
			//a[i]=0,f[i]=1;
		    i++;	
		    a[i]=b;
		}
		else 
		{
		   f[i]+=1;
		   if(i!=0)
		   {
			count+=f[i];
			//count++;
		   }
		   else
		   {
		       count=count+f[i]-1;
		   }
		}
	    }
	   /* printf("%d\n",count);
	    //printf("%d\n",i);
	    for(j=0;j<=i;j++)
	    {
		printf("%d---> %d %d\n",j,a[j],f[j]);
	    }
	    printf("\n");*/
	    //printf("%d\n",a[top]);
	    top++;
	}
	printf("%lld\n",count);
    }
    return 0;
}
