#include <stdio.h>
#include <stdlib.h>

struct node *createNode(int data); // creating a new node
// Traversals
void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);
// searching and inserting
struct node *search(struct node *root, int key);     // recursive search
struct node *IterSearch(struct node *root, int key); // Iterative search

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        printf(" %d ", root->data);
        postorder(root->right);
    }
}
struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key == root->data)
        return root;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct node *IterSearch(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating memory in heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left children to null
    n->right = NULL;                                // setting the right children to null
    return n;                                       // returning the created node
}
void main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // linking the root with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Preorder: ");
    preorder(p);
    printf("\n");
    printf("Postorder: ");
    postorder(p);
    printf("\n");
    printf("Inorder: ");
    inorder(p);
    printf("\n");

    struct node *n = search(p, 3);
    if (n != NULL)
        printf("Found: %d\n", n->data);
    else
        printf("Element not found!\n");

    struct node *m = IterSearch(p, 4);
    if (m != NULL)
        printf("Found: %d", m->data);
    else
        printf("Element not found!");
}