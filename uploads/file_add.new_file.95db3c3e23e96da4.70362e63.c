#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *next;
	int data;
	int d;
	int state;
}node;
int match(int x,int y)
{
	int i,count=0;
	for(i=1;i<=4;i++)
	{
		if(x%10==y%10)
			count++;
		x=x/10;y=y/10;
	}
	if(count==3)
		return 1;
}
int main()
{
	int a[10009]={0},i=2,j,p,k=2,tcase,ref;
	while(k<=100)
	{
		p=10000/k;
		for(j=2;j<=p;j++)
		{
			a[k*j]=1;
		}
		k++;
		for(;k<=100;k++)
		{
			if(a[k]==0)
			{
				break;
			}
		}
	}
	for(i=1000,j=-1;i<=10000;i++)
		if(a[i]==0)
			a[++j]=i;
	node *d[10000];
	for(i=0;i<=10000;i++)
	{
		d[i]=(node*)malloc(sizeof(node));
		d[i]->next=NULL;
		d[i]->state=0;
		d[i]->d=1000000000;
	}
	node *temp;
	for(i=0;i<=j;i++)
	{
		//printf("%d->",a[i]);
		for(k=0;k<=j;k++)
		{
			if((match(a[i],a[k]))==1)
			{
				temp=d[a[i]]->next;
				node *new=(node*)malloc(sizeof(node));
				new->next=temp;
				new->data=a[k];
				new->state=0;
				new->d=1000000000;
				d[a[i]]->next=new;
	//		printf("%d ",d[a[i]]->next->data);
			}
		}
	//	printf("\n");
	}
	int a1,a2;
	scanf("%d",&tcase);
	while(tcase--)	
	{
		scanf("%d%d",&a1,&a2);
		d[a1]->d=0;d[a1]->state=1;
		int start=0,end=-1;
		int q[100000];
		q[++end]=a1;
		while(start<=end)
		{
			ref=q[start];
			if(ref==a2)
				break;
			temp=d[ref]->next;
			while(temp!=NULL)
			{
				if(d[temp->data]->state==0)//d[temp->data]->state
				{
					d[temp->data]->state=1;
					d[temp->data]->d=d[ref]->d+1;
					q[++end]=temp->data;
				}
		/*		if(temp->data==a2)
				{
				    break;
				}*/
				temp=temp->next;
			}
/*			if(temp!=NULL && temp->data==a2)
			{
				break;
			}*/
			start++;
			d[ref]->state=2;
		}
		if(ref==a2)
			printf("%d\n",d[a2]->d);
		else 
			printf("Impossible\n");
		for(i=0;i<10000;i++)
		{
			d[i]->d=1000000000;
			d[i]->state=0;			
		}
	}	
	return 0;
}

