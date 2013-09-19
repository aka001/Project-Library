#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *right;
	struct node *left;
	int data;
}node;
char b[1000000];
node *a[1000000];
int pre(char c)
{
	if(c=='/'||c=='*')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else 
		return 3;
}
void inorder(node *root)
{
	if(root==NULL)
	{
		
		if(root->data=='/' || root->data=='*' || root->data=='+'||root->data=='-')
			printf("(");
		inorder(root->left);
		printf("%c",root->data);
		inorder(root->right);
		if(root->data=='/' || root->data=='*' || root->data=='+'||root->data=='-')
			printf(")");
	}
}
int main()
{
	int t;
	char x;
	scanf("%d%c",&t,&x);
	while(t--)
	{
		int i=-1,j=-1;
		char c;
		node *root=NULL;
		node *new=NULL;
		while((c=getchar())!='\n')
		{
			if((c>='0' && c<='9')||(c>='a'&&c<='z'))
			{
				new=(node*)malloc(sizeof(node));
				new->right=NULL;new->left=NULL;
				new->data=c;
				a[++i]=new;
			}
			else if(c=='/'||c=='*'||c=='+'||c=='-')
			{
				if(j==-1)
				{
					b[++j]=c;
				}
				else if(pre(c)>pre(b[i]) && j>=0)
					b[++j]=c;
				else
				{
					while(pre(c)<=pre(b[j]) && j>-1)
					{
						new=(node*)malloc(sizeof(node));
						new->right=a[i--];new->left=a[i--];
						new->data=b[j];
						a[++i]=new;
						j--;
					}
					b[++j]=c;
				}
			}
		}
		while(j>=0)
		{
			new=(node*)malloc(sizeof(node));
			new->right=a[i--];
			new->left=a[i--];
			new->data=b[j--];
			a[++i]=new;
		}
		inorder(a[i]);
		printf("\n");
	}
	return 0;
}
