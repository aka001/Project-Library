#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int l;
    int b;
}node;

int compare(void const *p1,void const *p2)
{
    const node *p=p1;
    const node *q=p2;
    if(p->l<q->l)
    {
	return -1;
    }
    else if(p->l==q->l)
    {
	return 0;
    }
    else if(p->l>q->l)
    {
	return 1;
    }
}

int main()
{
    int test,k,i,n,sum,cnt;
    node a[100007];
    scanf("%d",&test);
    while(test--)
    {
	int dif[100007]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d%d",&a[i].b,&a[i].l);
	}
	k=n-1;
	qsort(a,n,sizeof(a[0]),compare);
	cnt=1;
	sum=0;
	dif[cnt]=1;
	for(i=1;i<n;i++)
	{
	    if(a[i].b!=a[i-1].b)
	    {
		cnt++;
	    }
	    dif[cnt]++;
	}
	for(i=cnt;i>=0;i--)
	{
	    while(dif[i]!=0)
	    {
		if(k==-1)
		{
		    break;
		}
		sum+=(i*a[k].l);
		k--;
		dif[i]--;
	    }
	    if(k==-1)
	    {
		break;
	    }
	}
	printf("%d\n",sum);
    }
    return 0;
}
