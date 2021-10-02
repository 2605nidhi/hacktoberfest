#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create_node(int val)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->right=temp->left=NULL;
    return temp;
};

struct node *insert(struct node *tree,int key)
{
    if(tree==NULL)
    {
        struct node *temp = create_node(key);
        printf("\nNode inserted successfully\n");
        return temp;
    }
    else
    {
        if(tree->data>key) tree->left=insert(tree->left,key);
        else tree->right = insert(tree->right,key);
    }
    return tree;
}

struct node *search(struct node *tree,int key)
{
    if(tree==NULL||tree->data==key) return tree;
    else{
        if(tree->data>key) return search(tree->left,key);
        else return search(tree->right,key);
    }
}

void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("\t %d",tree->data);
        inorder(tree->right);
    }
}
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("\t %d",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("\t %d",tree->data);
    }
}
void display(struct node *tree)
{
    printf("\n1. Inorder traversal \n2. Preorder traversal \n3. Postorder traversal \nEnter your choice : ");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            inorder(tree);
            break;
        case 2:
            preorder(tree);
            break;
        case 3:
            postorder(tree);
            break;

    }
}

struct node *findMax(struct node*tree)
{
    struct node*temp=tree;
    while(temp->right!=NULL) temp=temp->right;
    return temp;
};

struct node *delete_node(struct node *tree, int key)
{
    if(tree!=NULL)
    {
        if(tree->data==key)
        {
            if(tree->left==NULL&&tree->right==NULL)
            {
                free(tree);
                return NULL;
            }
            else if(tree->left==NULL)
            {
                struct node *temp= tree->right;
                free(tree);
                return temp;
            }
            else if(tree->right==NULL)
            {
                struct node *temp= tree->left;
                free(tree);
                return temp;
            }
            else
            {
                struct node *max= findMax(tree->left);
                tree->data=max->data;
                tree->left=delete_node(tree->left,max->data);
            }
        }
        else
        {
            if(tree->data>key) tree->left=delete_node(tree->left,key);
            else tree->right = delete_node(tree->right,key);
        }
    }
    else
    {
        printf("\nNo such node found");
        return NULL;
    }
};

int bst()
{
    struct node *root =NULL, *temp;
    int ch;
    while(1)
    {
        printf("\n1. Insert a node \n2. Search \n3. Delete \n4. Display \n5. Exit \nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter value to be inserted.\n");
                int key;
                scanf("%d",&key);
                root=insert(root,key);
                break;
            case 2:
                printf("\nEnter value to be searched.\n");
                scanf("%d",&key);
                temp=search(root,key);
                if(temp==NULL) printf("\nNo such node found.\n");
                else printf("\nNode with value %d is at address %x",key,temp);
                break;
            case 3:
                printf("\nEnter value to be deleted.\n");
                scanf("%d",&key);
                root=delete_node(root,key);
                break;
            case 4:
                display(root);
                break;
            case 5:
                exit(1);
        }
    }
    return 0;
}
