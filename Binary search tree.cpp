#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
	struct node *root=NULL;
struct node *insert (struct node *root,int ele);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
int main()
{
	int ele,ch;
	while(1)
	{
	printf("\n\t1.insert\n\t2.inorder\n\t3.preorder\n\t4.postorder\n\t5.exit\t");
	printf("\n enter ch value");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("\n enter element to be insert ");
		scanf("%d",&ele);
		root=insert(root,ele);
		break;
		case 2: inorder(root);
		break;
		case 3: preorder(root);
		break;
		case 4: postorder(root);
		break;
	}
}
}
void inorder(struct node *ele)
{
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void preorder(struct node *ele)
{
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *ele)
{
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}
struct node *insert(struct node *root,int ele)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(root==NULL)
	{
		newnode->data=ele;
		newnode->left=NULL;
		newnode->right=NULL;
	}
	else if(ele>root->data)
	{
	root->right=insert(root->right,ele);
	}
	else
	{
	root->left=insert(root->left,ele);	
	}
	return root;
}
