#include<stdio.h>
#include<string.h>
char a[1000000]={0},b[1000000]={0};
int a1[1000000]={0},b1[1000000]={0};
int a3[1000000]={0},a4[1000000]={0},p[1000000]={0},q[1000000]={0};
int r1[1000000]={0};
int add(int len1,int len2)
{
    int i,j,flag=0,c=0,len;
    if(len1<len2)
    {
	len=len1;
	flag=1;
    }
    else
    {
	len=len2;
	flag=2;
    }
    for(i=0;i<len;i++)
    {
	r1[i]=a1[len1-i-1]+b1[len2-1-i]+c;
	c=r1[i]/10;
	r1[i]=r1[i]%10;
    }
    if(flag==1)
    {
	while(i!=len2)
	{
	    r1[i]=b1[len2-1-i]+c;
	    c=r1[i]/10;
	    r1[i]=r1[i]%10;
	    i++;
	}
    }
    else if (flag==2)
    {
	while(i!=len1)
	{
	    r1[i]=a1[len1-1-i]+c;
	    c=r1[i]/10;
	    r1[i]=r1[i]%10;
	    i++;
	}
    }
    if(c!=0)
    {
	r1[i]=r1[i]+c;
	i++;
    }
    return i;
}

int mult(int len1,int len2)
{
    int i,j,k,c=0,l;
    k=0;
    for(i=0;i<len1;i++)
    {	k=i;
	for(j=0;j<len2;j++)
	{
	    a3[k]=a3[k]+a1[len1-i-1]*b1[len2-j-1]+c;
	    c=a3[k]/10;
	    a3[k]=a3[k]%10;
	    k++;
	}
	if(c!=0)
	{
	    while(c!=0)
	    {
		a3[k]=a3[k]+c;
		c=c/10;
		a3[k]=a3[k]%10;
		k++;
	    }
	}
    }
    return k;
}

int node(int len,int r[])
{
    int i,j,count=0,f,c,temp;
    while(1)
    {
	f=1;
	c=0;
	for(i=0;i<len;i++)
	{
	    /*temp=r[i]+10*c;
	    r[i]=temp/2;
	    c=temp%2;*/
	    if(r[i]%2==0)
	    {
		r[i]=r[i]/2;
	    }
	    else
	    {
		r[i]=r[i]/2;
		if(i<len-1)
		{
		    r[i+1]=r[i+1]+10;
		}
	    }
	    if(r[i]!=0)
		f=0;
	}
	count++;
	if(f==1)
	    break;
	//count++; 
    }
    return count;
}
void char2int(char a[1000000],int b[1000000],int l)
{
    int i;
    for(i=0;i<l;i++)
    {
	b[i]=a[i];
    }
}
int main()
{
    int s3,len1,len4=1000000,len2,len3=0,i,j,test,s1,temp,s2,count,first,f;
    char ch;
    scanf("%s %s",a,b);
    len1=strlen(a);
    for(i=0;i<len1;i++)
    {
	a[i]=a[i]-'0';
    }
    //strcpy(a1,a);
    len2=strlen(b);
    for(i=0;i<len2;i++)
    {
	b[i]=b[i]-'0';
    }
    char2int(a,a1,len1);
    char2int(b,b1,len2);
    for(i=0;i<len1;i++)
    {
	p[i]=a1[i];
    }
    for(i=0;i<len2;i++)
    {
	q[i]=b1[i];
    }
    s1=node(len1,p);
    s2=node(len2,q);
    scanf("%d",&test);
    getchar();
    while(test!=0)
    {
	ch=getchar();
	if(ch=='A')
	{
	    len3=add(len1,len2);
	    for(i=0;i<len3;i++)
	    {
		a4[i]=a3[len3-1-i];
	    }
	    count=0;
	    while(1)
	    {
		f=0;
		for(i=0;i<len3;i++)
		{
		    if(a4[i]%2==0)
		    {
			a4[i]=a4[i]/2;
		    }
		    else 
		    {
			a4[i]=a4[i]/2;
			if(i<len3-1)
			{
			    a4[i+1]=10+a4[i+1];
			}
		    }
		    if(a4[i]!=0)
		    {
			f=1;
		    }
		}
		count++;
		if(f==0)
		{
		    break;
		}
	    }
	    s3=count;
	    for(i=0;i<len3;i++)
	    {
		a4[i]=0;
	    }
	    getchar();
	    test--;
	}	
	else if(ch=='M')
	{
	    /*for(i=0;i<1000000;i++)
	    {
		a3[i]=0;
	    }*/
	    len3=mult(len1,len2);
	    s3=s1+s2-1;
	    getchar();
	    test--;
	}
	else if(ch=='P')
	{
	    for(i=len3-1;i>=0;i--)
	    {
		printf("%d",a3[i]);
	    }
	    printf("\n");
	}
	else if(ch=='O')
	{
	    int height=2;
	    int r2[1000000]={0};
	    int po=1;
	    while(po<=height)
	    {
	    	len3=mult(len1,len2);
	    	for(i=0;i<len3;i++)
	    	{
			temp=a3[i];
			a3[i]=a3[len3-1-i];
			a3[len3-i-1]=temp;
		}
	    	len4=add(len4,len3);
		for(i=0;i<len3;i++)
		{
		    a1[i]=a3[i];
		    b1[i]=a3[i];
		}
		po++;
	    }
	    for(i=len4-1;i>=0;i--)
	    {
		printf("%d",r1[i]);
	    }
	    printf("\n");
	}
	else if(ch=='S')
	{
	    scanf("%d",&first);
	    if(first==1)
	    {
		printf("%d\n",s1);
	    }
	    else if(first==2)
	    {
		printf("%d\n",s2);
	    }
	    else
	    {
		printf("%d\n",s3);
	    }
	}
	else
	{
	    test--;
	}

    }
    return 0;
}
