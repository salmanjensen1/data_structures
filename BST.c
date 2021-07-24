#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node Node;
Node* tree=NULL;

Node* createNode(int data);
void insert(int data);
void inorderTraversal(Node* root);
Node* searchElement(int data, Node* root);

int main()
{

    insert(10);
    insert(3);
    insert(2);
    insert(13);
    insert(6);
    insert(4);
    insert(17);
    insert(7);

    printf("Looking for change for git\n");

    inorderTraversal(tree);
    bool flag = false;
    if(searchElement(13, tree))
    {
        printf("Element is present");
    }
}


Node* createNode(int data)
{
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->left=newnode->right=NULL;
    newnode->data = data;
    return newnode;
}

void inorderTraversal(Node* root)
{
    if(root!=NULL)
    {
        inorderTraversal(root->left);
        printf("%d\n", root->data);
        inorderTraversal(root->right);
    }
}

void insert(int data)
{
    Node* newnode;
    Node* nodeptr;
    Node* parentptr;
    newnode=createNode(data);
    if(tree==NULL)
    {
        tree=newnode;
    }
    else
    {
        nodeptr=tree;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(data<nodeptr->data)
                nodeptr=nodeptr->left;
            else
                nodeptr=nodeptr->right;
        }
        if(data<parentptr->data)
            parentptr->left = newnode;
        else
            parentptr->right=newnode;

    }
}

Node* searchElement(int data, Node* root)
{
    if(root==NULL || data==root->data)
        return root;
    else
    {
        if(data < root->data)
            root = searchElement(data, root->left);
        else if(data > root->data)
            root = searchElement(data, root->right);
    }


}
