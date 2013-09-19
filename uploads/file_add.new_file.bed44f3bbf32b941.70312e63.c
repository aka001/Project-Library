#include<stdio.h>
long long int min[2000010],max[2000010];
long long int mi=0,ma=0;
void minswap(long long int x,long long int y)
{
    long long int temp=min[x];
    min[x]=min[y];
    min[y]=temp;
}
void maxswap(long long int x,long long int y)
{
    long long int temp=max[x];
    max[x]=max[y];
    max[y]=temp;
}
void minin(long long int num)
{
    min[++mi]=num;long long int i,p,state=0;
    i=mi;
    while(i!=1 && state==0)
    {
	p=i/2;
	if(min[p]>min[i])
	{
	    minswap(p,i);
	    i=p;
	}
	else
	    state=1;
    }
}
void maxin(long long int num)
{
    max[++ma]=num;long long int i,p,state=0;
    i=ma;
    while(i!=1 && state==0)
    {
	p=i/2;
	if(max[p]<max[i])
	{
	    maxswap(p,i);
	    i=p;
	}
	else 
	    state=1;
    }
}
long long int minno(long long int x,long long int y)
{
    if(min[x]<min[y])
	return x;
    return y;
}
long long int maxno(long long int x,long long int y)
{
    if(max[x]>max[y])
	return x;
    return y;
}
void mindel()
{
    min[1]=min[mi];long long int i=1;mi--;
    while(i<=mi/2)
    {
	if(min[i]>min[2*i]||min[i]>min[2*i+1])
	    {
		minswap(minno(2*i,2*i+1),i);
		i=minno(2*i,2*i+1);
	    }
	else
	{
	    break;
	}
    }
}
void maxdel()
{
    max[1]=max[ma];long long int i=1;ma--;
    while(i<=ma/2)
    {
	if(max[i]<max[2*i]||max[i]<max[2*i+1])
	{
	    maxswap(maxno(2*i,2*i+1),i);
	    i=maxno(2*i,2*i+1);
	}
	else
	{
	    break;
	}
    }
}
int main()
{
    long long int a,b,c,n,t,i,j;
    long long int new,sum;
   // min[0]=-1;max[0]=1000000007;
    scanf("%lld",&t);
    while(t--)
    {
	ma=0;mi=0;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
	max[++ma]=1;sum=1;
	for(i=2;i<=n;i++)
	{
	    new=(a*max[1]+b*i+c)%1000000007;
	    sum+=new;
	    if(new>max[1])
	    {
		minin(new);
	    }
	    else
	    {
		maxin(new);
	    }
	    if(ma!=mi && ma!=mi+1)
	    {
		if(ma>mi+1)
		{
		    minin(max[1]);
		    maxdel();
		}
		else
		{
		    maxin(min[1]);
		    mindel();
		}
	    }
	}
	printf("%lld\n",sum);
    }
    return 0;
}
