#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

Node *search(Node *root, int key){
    if (root == NULL || root->data == key){
        return root;
    }
    if (key < root->data){
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node *findMin(Node *root)
{
    Node *current = root;

    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL){
        return root;
    }
    if (key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if (root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void display(Node *root)
{
    printf("\nPreorder Traversal  : ");
    preorder(root);

    printf("\nInorder Traversal   : ");
    inorder(root);

    printf("\nPostorder Traversal : ");
    postorder(root);

    printf("\n");
}

void main()
{
    Node *root = NULL;
    Node *result;

    int values[10] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 90};

    printf("Creating Binary Search Tree with nodes {50, 30, 70, 20, 40, 60, 80, 10, 35, 90}\n");

    for (int i = 0; i < 10; i++)
    {
        root = insert(root, values[i]);
    }

    printf("\nOriginal Binary Search Tree:");
    display(root);

    int key = 40;

    printf("\nSearching for node %d...\n", key);

    result = search(root, key);

    if (result != NULL)
    {
        printf("Node %d found in the BST.\n", key);
    }
    else
    {
        printf("Node %d not found in the BST.\n", key);
    }
    printf("\nInserting node 45...\n");
    root = insert(root, 45);

    printf("BST after insertion:");
    display(root);

    printf("\nDeleting node 30...\n");
    root = deleteNode(root, 30);

    printf("BST after deletion:");
    display(root);
}