#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node* left;
     struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;

     return(node);
}
struct node* insert(struct node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);

    /* Otherwise, recur down the tree */
    if (data < node->data)
        node->left  = insert(node->left,data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    /* return the (unchanged) node pointer */
    return node;
}
/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
     if (node == NULL)
        return;

     // first recur on left subtree
     printPostorder(node->left);

     // then recur on right subtree
     printPostorder(node->right);

     // now deal with the node
     printf("%d ", node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the data of node */
     printf("%d ", node->data);

     /* now recur on right child */
     printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first print data of node */
     printf("%d ", node->data);

     /* then recur on left sutree */
     printPreorder(node->left);

     /* now recur on right subtree */
     printPreorder(node->right);
}
int main()
{
     struct node *root = NULL;
     root=insert(root, 22);
     root=insert(root, 45);
     root=insert(root, 21);
     root=insert(root, 89);
     root=insert(root, 69);
     root=insert(root, 35);
     root=insert(root, 81);
     printf("\nPreorder traversal of binary search tree is \n");
     printPreorder(root);

     printf("\nInorder traversal of binary search tree is \n");
     printInorder(root);

     printf("\nPostorder traversal of binary search tree is \n");
     printPostorder(root);

     return 0;
}
