#include<stdio.h>
int a[2][100000]={0},b[1000000];
int main()
{
    int n,i,c,d,pos,l,k,flag=0,j,fl=0;
    scanf("%d",&n);
    k=1;
    for(i=0;i<2*n;i++)
    {
	scanf("%d %d",&c,&d);
	if(a[0][c]==0)
	{
		a[0][c]=d;
	}
	else
	  {
	      a[1][c]=d;
	  
	  	if(c==n)
		{
		    if((d!=1)||(d!=2))
		    {
			fl=1;
		    }
		}
		else if(c==n-1)
		{
		    if((d!=n)||(d!=1))
		    {
			fl=1;
		    }
		}
		else
		{ if(c>d)
		    {
			l=c-d;
		    }
		    else
		    {
			l=d-c;
		    }
		    if((l!=1)||(l!=2))
		    {
			fl=1;
		    }

		}


	  }
	    	
    }
    i=1;
    j=1;
    b[0]=1;
    k=1;
    while(i<=n)
    {
	
	    if(a[0][a[0][j]]==a[1][j]||(a[1][a[0][j]]==a[1][j]))
	    {
		b[k]=a[0][j];
	        j=b[k];
		k++;
	     	
	    }
	    else if(a[0][a[1][j]]==a[0][j]||(a[1][a[1][j]]==a[0][j]))
		    {
		    	b[k]=a[1][j];
		    	j=b[k];
			k++;
		    }
	i++;
    }
    for(i=0;i<k-1;i++)
    {
	printf("%d ",b[i]);
    }
	printf("\n");
    

    return 0;
}

