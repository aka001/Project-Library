#include<stdio.h>
int min(int a[],int x,int y)
{
	if(a[x]<a[y])
		return x;
	return y;
}
int max(int a[],int x,int y)
{
	if(a[x]>a[y])
		return x;
	return y;
}
int main()
{
	int n,k,p,i,j,temp,istart=0,jstart=0,num,state=0,mi,a[1000000]={0},st[1000000]={0},b[1000000],ma,del=0,count=0;
	scanf("%d",&n);
	long long int sum=0;
	a[0]=-1;b[0]=1000000000;
	while(n--)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&num);
			a[++istart]=num;state=0;i=istart;st[num]++;b[++jstart]=num;count++;
			while(state==0 &&i!=0)
			{
				p=i/2;
				if(a[p]>a[i])
				{
					temp=a[i];
					a[i]=a[p];
					a[p]=temp;
					i=p;
				}
				else
					state=1;
			}
			j=jstart;state=0;
			while(state==0 && j!=0)
			{
				p=j/2;
				if(b[p]<b[j])
				{
					temp=b[j];
					b[j]=b[p];
					b[p]=temp;
					j=p;
				}
				else
					state=1;
			}
		}
		sum+=b[1]-a[1];
		st[a[1]]--;
		a[1]=a[istart];istart--;i=1;del++;
		while(i<=istart/2 && (a[i]>a[2*i]||a[i]>a[2*i+1]))
		{
			mi=min(a,2*i,2*i+1);
			temp=a[i];
			a[i]=a[mi];
			a[mi]=temp;
			i=mi;
		}
		while(del<count && st[a[1]]==0)
		{
			a[1]=a[istart];istart--;i=1;
			while(i<=istart/2 && (a[i]>a[2*i]||a[i]>a[2*i+1]))
			{
				mi=min(a,2*i,2*i+1);
				temp=a[i];
				a[i]=a[mi];
				a[mi]=temp;
				i=mi;del++;
			}
		}
		st[b[1]]--;
		b[1]=b[jstart];j=1;jstart--;del++;
		while(j<=jstart/2 && (b[j]<b[2*j]||b[j]<b[2*j+1]))
		{
			ma=max(b,2*j,2*j+1);
			temp=b[j];
			b[j]=b[ma];
			b[ma]=temp;
			j=ma;
		}
		while(del<count && st[b[1]]==0)
		{
			b[1]=b[jstart];jstart--;j=1;
			while(j<=jstart/2 &&(b[j]<b[2*j]||b[j]<b[2*j+1]))
			{
				ma=max(b,2*j,2*j+1);
				temp=b[j];
				b[j]=b[ma];
				b[ma]=temp;
				j=ma;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}

