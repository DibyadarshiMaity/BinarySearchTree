#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	struct n*left,*right;
	int data;
}node;
node* cnode(int n)
{
	node*New;
	New=(node*)malloc(sizeof(node));
	New->data=n;
	New->left=NULL;
	New->right=NULL;
	return New;
}
node* addBst(node*root,int value)
{
	if(root==NULL)
	  return(cnode(value));
	else if(value<root->data)
	 root->left=addBst(root->left,value);
	else if(value>=root->data)
	root->right=addBst(root->right,value);
	return root;
}
 void inorder(node*root)
 {
 	if(root==NULL)
 	 return;
 	inorder(root->left);
 	printf("%d\t;",root->data);
 	inorder(root->right);
 }
 void preorder(node*root)
 {
 	if (root==NULL)
 	return;
 	printf("%d\t;",root->data);
 	preorder(root->left);
 	preorder(root->right);
 	
 }
 void postorder(node*root)
 {
 	if(root==NULL)
 	return;
 	postorder(root->left);
 	postorder(root->right);
 	printf("%d\t",root->data);
 	
 }
 main()
{
	int num,i,n;
	node*root=NULL;
	printf("Enter the no of nodes you want to create\n");
	scanf("%d",&n);
 	for(i=1;i<=n;i++)
	 {
	 	printf("enter the number");
	 	scanf("%d",&num);
	 	root=addBst(root,num);
	}
	printf("The inorder traversal is\n");
	inorder(root);
	printf("\nThe preorder traversal is \n");
	preorder(root);
	printf("\nThe post order traversal is\n");
	postorder(root);
}