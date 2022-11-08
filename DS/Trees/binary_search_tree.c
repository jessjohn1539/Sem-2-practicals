//////////////////////ATTENTION: dont use this program////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BSTnode
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *root; // address of root node
node *insert(node *root, int data);
node *GetNewNode(int data);
int search(node *root, int data);
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        // empty tree
        root = GetNewNode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
node *GetNewNode(int data)
{
    node *NewNode = (node *)malloc(sizeof(node *));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}
int search(node *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}
int main()
{
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    int n;
    printf("Enter a number to be searched: ");
    scanf("%d", &n);
    if (search(root, n) == true)
        printf("Number found!\n");
    else
        printf("Number not found!\n");
}