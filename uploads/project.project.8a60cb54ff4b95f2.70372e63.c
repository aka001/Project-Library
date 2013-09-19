#include<stdio.h>
#include<string.h>

int as[128],bs[128];
char a[1000000],b[100000];
int main()
{
    int test,i,len,j,len2,flag,count;
    scanf("%d",&test);
    while(test--)
    {
	flag=0,count=0;
	scanf("%s",a);
	scanf("%s",b);
	for(i=0;i<128;i++)
	{
	    as[i]=0;
	    bs[i]=0;
	}
	len2=strlen(b);
	for(i=0;b[i]!='\0';i++)
	{
	    as[b[i]]=as[b[i]]++;
	}
	len=strlen(a);
	for(i=0;i<128;i++)
	{
	    if(as[i]>0)
	    {
		count++;
	    }
	}
	flag=0;
	i=-len2;
	j=0;
	while(j<len)
	{

	    if(bs[a[j]]==as[a[j]])
	    {
		count++;
	    }
	    bs[a[j]]++;
	    if(bs[a[j]]==as[a[j]])
	    {
		count--;
	    }
	    if(i>=0)
	    {
		if(bs[a[i]]==as[a[i]])
		{
		    count++;
		}
		bs[a[i]]--;
		if(bs[a[i]]==as[a[i]])
		{
		    count--;
		}
	    }
	    if(count==0)
	    {
		flag++;
	    }
	    printf("%d %d %d\n",count,i,j);
	    j++;
	    i++;
	}
	printf("%d\n",flag);
    }
    return 0;
}
