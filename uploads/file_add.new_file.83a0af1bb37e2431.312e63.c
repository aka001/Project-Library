#include<stdio.h>
int a[1000][10000];
int main()
{
    int i,j,row,col,count;
    for(i=0;i<5;i++)
    {
    for(j=0;j<5;j++)
    {
	scanf("%d",&a[i][j]);
    	if(a[i][j])
	{

	    row=i;
	    col=j;
	}
    }
    }
    if(row>2)
    {
	row-=2;
    }
    else

    {
	row=2-row;
    }
    if(col>2)
    {
	col-=2;
    }
    else
    {
	col=2-col;
    }
    printf("%d\n",row+col);
return 0;
}

    
