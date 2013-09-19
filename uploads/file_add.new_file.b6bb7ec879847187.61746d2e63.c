#include<stdio.h>
int main()
{
		int a;
		float b;
		scanf("%d %f",&a,&b);
		if(((a%5)==0)&&(a<b))
		{  b=b-a-0.50;}
		printf("%0.2f\n",b);
		return 0;
}
