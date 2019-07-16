#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node *left, *right;
};

// To create new BST Node
struct Node* newNode(int item)
{
    struct Node *temp =(struct Node *)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// To insert a new node in BST
struct Node* insert(struct Node* node, int key)
{
    // if tree is empty return new node
    if (node == NULL)
        return newNode(key);

    // if key is less then or grater then
    // node value then recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

// function to find max value less then N
int findMaxforN(struct Node* root, int N)
{
    // Base cases
    if (root == NULL)
        return -1;
    if (root->key == N)
        return N;

    // If root's value is smaller, try in rght
    // subtree
    else if (root->key < N)
    {
        int k = findMaxforN(root->right, N);
        if (k == -1)
            return root->key;
        else
            return k;
    }

    // If root's key is greater, return value
    // from left subtree.
    else if (root->key > N)
        return findMaxforN(root->left, N);
}

// Driver code
int main()
{
    int N = 6;
    struct Node* root = NULL;
    root=insert(root, 5);
    root=insert(root, 2);
    root=insert(root, 1);
    root=insert(root, 3);
    root=insert(root, 12);
    root=insert(root, 9);
    root=insert(root, 21);
    root=insert(root, 19);
    root=insert(root, 25);

    printf("Largest number in a binary search tree which is less than equal to %d is %d",N,findMaxforN(root, N));
    return 0;
}
