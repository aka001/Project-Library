#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *next;
	int ver;
	int k;
	int w;
	int d;
}node;
typedef struct p{
	int data;
	int index;
}p;
p d[10000];
node *a[10000];
int start;
void swap(int x,int y)
{
	int temp=d[x].data;
	d[x].data=d[y].data;
	d[y].data=temp;
}
void swapind(int x,int y)
{
	int temp=d[x].index;
	d[x].index=d[y].index;
	d[y].index=temp;
}
int min(int x,int y)
{
	if(d[x].data>d[y].data)
		return y;
	return x;
}
void minheap(int data,int ind)
{
	int state=0,p;
	d[++start].data=data;
	d[start].index=ind;
	int i;i=start;
	while(state==0 && i!=0)
	{
		p=i/2;
		if(d[p].data>d[i].data)
		{
			swap(p,i);swapind(p,i);
			i=p;
		}
		else
			state=1;
	}
}
int delmin()
{
	int mi;
	if(start==0)
		return -1;
	int t=d[1].index;
	d[1].data=d[start].data;d[1].index=d[start].index;start--;int i=1;
	while(i<=start/2 && (d[i].data>d[2*i].data||d[i].data>d[2*i+1].data))
	{
		mi=min(2*i,2*i+1);
		swap(mi,i);swapind(mi,i);
		i=mi;
	}
	return t;
}
int main()
{
	d[0].data=-1;
	int i,n,m,s,t,min,u,v,w;
	for(i=0;i<10000;i++)
	{
		a[i]=(node*)malloc(sizeof(node));
		a[i]->next=NULL;
		a[i]->d=1000000000;
		a[i]->k=0;
	}
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		node *new=(node*)malloc(sizeof(node));
		new->next=a[u]->next;
		new->ver=v;
		new->w=w;
		new->d=1000000000;
		a[u]->next=new;
		new=(node*)malloc(sizeof(node));
		new->next=a[v]->next;
		new->ver=u;
		new->w=w;
		new->d=1000000000;
		a[v]->next=new;
	}
	scanf("%d%d",&s,&t);
	a[s]->d=0;
	minheap(a[s]->d,s);
	while(1)
	{
		min=delmin();
		a[min]->k=1;
		node *temp=a[min]->next;
		while(temp!=NULL)
		{
			if(a[temp->ver]->k==0)
			{
				if((a[min]->d+temp->w)<a[temp->ver]->d)
				{
					a[temp->ver]->d=a[min]->d+temp->w;
					minheap(a[temp->ver]->d,temp->ver);
				}
			}
			temp=temp->next;
		}
		if(min==-1 || min==t)
			break;
	}
	if(min==t)
		printf("%d\n",a[t]->d);
	else 
		printf("-1\n");
	return 0;
}
