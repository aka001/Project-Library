#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int compare(void const *p1,void const *p2)
{
    return *(char *)p1 - *(char *)p2;
}
int counter=0;
void merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    i=left;
    j=mid+1;
    k=-1;
    while(i<=mid&&j<=right)
    {
	if(arr[i]<arr[j])
	{
	    temp[++k]=arr[i];
	    i++;
	}
	/*else if (arr[i]>arr[j]){
	    temp[++k]=arr[j];
	    counter+=(j-(left+k));
	    j++;
	}*/
	else
	{

	    temp[++k]=arr[j];
	    counter+=(j-(left+k));
	    j++;
	}
    }
    while(i<=mid)
    {
	temp[++k]=arr[i];
	i++;
    }
    while(j<=right)
    {
	temp[++k]=arr[j];
	j++;
    }
    while(k>=0)
    {
	arr[right--]=temp[k--];
    }
}
void partition(int arr[],int temp[],int left,int right)
{
    if(left>=right)
	return;
    partition(arr,temp,left,(left+right)/2);
    partition(arr,temp,(left+right)/2+1,right);
    merge(arr,temp,left,(left+right)/2,right);
}
int main()
{
    int i,j,q,val,ind,count,add;
    int a[100000],temp[100000],temp1[100000];
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
	scanf("%d",&a[i]);
	temp1[i]=a[i];
    }
    scanf("%d",&q);
    while(q--)
    {
	add=0;
	count=0;
	counter=0;
	scanf("%d %d",&ind,&val);
	a[ind-1]=val;
	temp1[ind-1]=val;
	qsort(temp1,j,sizeof(temp1[0]),compare);
	i=1;
	while(i<j)
	{
		if(temp1[i]!=temp1[i-1])
		{
		    count+=i;
		    add=i;
		}
		else
		{
		    count+=add;
		}
		i++;
	}
    	partition(a,temp,0,j-1);
	printf("%d\n",count);
	printf("%d\n",counter);
    	//printf("%d\n",count-counter);
    }
    return 0;
}
