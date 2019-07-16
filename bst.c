#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *l;
	struct node *r;
};

struct node *t=NULL;
struct node *t1;
///////////////////////// Insertion ///////////////////////////////////////
struct node *insert(int val, struct node *t)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));

	if(t==NULL)
	{
		nn->data=val;
		nn->l=nn->r=NULL;
		t=nn;
	}

	else if(val < t->data)
		t->l=insert(val, t->l);

	else
		t->r=insert(val, t->r);

	return t;
}

//////////////////////// Inorder Predecessor ////////////////////////////
struct node *minvaluenode(struct node *n)
{
	struct node *curr;
	curr=n;

	while (curr->l!=NULL)
		curr=curr->l;

	return curr;
}

//////////////////////// Deletion ///////////////////////////////////////
struct node *delete(int val, struct node *t)
{
	struct node *temp;
	// Base Case
	if (t==NULL) return t;

	if (val < t->data) t->l = delete (val, t->l);

	else if (val > t->data) t->r = delete (val, t->r);

	else
	{
		if(t->l==NULL) // Only right child
		{
			temp=t->r;
			free(t);
			return temp;
		}

		if(t->r==NULL) //Only left child
		{
			temp=t->l;
			free(t);
			return temp;
		}

		// If both the child exists
		temp= minvaluenode(t->r); // Inorder Predecessor
		t->data=temp->data;
		t->r=delete(temp->data, t->r);
	}

	return t;
}


//////////////////  Preorder Traversal  ////////////////////////////
void preorder(struct node *t)
{
	if(t!=NULL)
	{
		printf("%d ", t->data);
		preorder(t->l);
		preorder(t->r);
	}
}


/////////////// Inorder Traversal ////////////////////////////////////
void inorder(struct node *t)
{
	if(t!=NULL)
	{
		inorder(t->l);
		printf("%d ", t->data);
		inorder(t->r);
	}
}

/////////////// Postorder Traversal ////////////////////////////////////
void postorder(struct node *t)
{
	if(t!=NULL)
	{
		postorder(t->l);
		postorder(t->r);
		printf("%d ", t->data);
	}
}


///////////////////////////////////// Height of tree ////////////////////

int height (struct node *t)
{
	int lh=0, rh=0;
	if(t==NULL)
		return 0;

	else
	{
		lh=height(t->l);
		rh=height(t->r);
	}

	if(lh>=rh)
		return (1+lh);

	else
		return (1+rh);

}

//////////////////////////// Number of nodes in trees //////////////////
int count_nodes (struct node *t)
{
	if(t==NULL)
		return 0;

	else
		return(count_nodes(t->l) + count_nodes(t->r) + 1);
}

///////////////// Mirror Image of tree ////////////////////////////
struct node *mirror(struct node *t1)
{
	struct node *temp;
	if (t1!=NULL)
	{
		temp=t1->l;
		t1->l=t1->r;
		t1->r=temp;

		mirror(t1->l);
		mirror(t1->r);
	}

	return t1;

}

void main()
{
	int n, val, h, c;
	printf("\n\n Enter choice:");
	t=insert(60,t);
	t=insert(80,t);
	t=insert(40,t);
	t=insert(20,t);

	printf("\n \n Preorder traversal for tree is: ");
	preorder(t);

	printf("\n \n Postorder traversal for tree is: ");
	postorder(t);

	printf("\n \n Inorder traversal for tree is: ");
	inorder(t);

	printf("\n 1. insert\n 2. delete\n 3. preorder\n 4. height of tree\n 5. mirror image\n 6. Exit\n 7. Number of nodes in tree\n");
	scanf("%d", &n);

	do
	{
		switch(n)
		{
			case 1: printf("\n Enter value to be inserted");
				scanf("%d", &val);
				t=insert(val,t);
				break;

			case 2: printf("\n Enter value to be deleted");
				scanf("%d", &val);
				t=delete(val,t);
				break;

			case 3: preorder(t);
				break;

			case 4: h=height(t);
				printf("\n Height of the tree is %d",h);
				break;

			case 5:	t1=t;
				printf("\n Preorder traversal of original tree:");
				preorder(t1);
				t1=mirror(t1);
				printf("\n Preorder traversal of mirror image of original tree:");
				preorder(t1);
				break;

			case 6: break;

			case 7: c=count_nodes(t);
				printf("\n Number of nodes in the tree is %d",c);
				break;


		}

		if (n!=6)
		{
			printf("\n\n Enter choice:");
			printf("\n 1. insert\n 2. delete\n 3. preorder\n 4. height of tree\n 5. mirror image\n 6. Exit\n 7. Number of nodes in tree\n");
			scanf("%d", &n);

		}

		else
			break;
	}while(1);

}

/////////////
void printLeafNodes(Node *root)
{
    // if node is null, return
    if (!root)
        return;

    // if node is leaf node, print its data
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }

    // if left child exists, check for leaf
    // recursively
    if (root->left)
       printLeafNodes(root->left);

    // if right child exists, check for leaf
    // recursively
    if (root->right)
       printLeafNodes(root->right);
}





