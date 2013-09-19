#include<stdio.h>
#include<math.h>
int main()
{	int i,j,b,fl,a[100],n,c[100],k,count,l,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{   scanf("%d",&a[i]);}
	for(i=0;i<pow(2,n);i++)
	{	
	    b=i;
	    k=0;
		for(j=0;j<n;j++)
		{
		    if(b&1)
			{
			    //printf("%d ",a[j]);
			    c[k]=a[j];
			    k++;
			}	
		    b=b>>1;
		}
		j=0,count=0,l=0,fl=0;
		while(j<k)
		{
		   
		    if(l==k-1)
		    {
			l=0;
			j++;
			if(fl==0)
			{
			    count--;
			}
			else
			{
			    fl=1;
			}
		    }
		    if(c[l]==a[j])
		    {
			count++;
			j++;
			l++;
			fl=1;
		    }
		    else
		    {
			//count--;
			l++;
		    }
		}
		if(count>0)
		{
		    cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}	
