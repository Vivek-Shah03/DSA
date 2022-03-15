#include <stdio.h>
struct node{
    char data;
    struct node *left;
    struct node *right;
};
struct node* createNode(char val)
{
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = val;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}
void INORDER(struct node* root)
{
    if(root == NULL){
        return;
    }
    INORDER(root->left);
    printf("%c",root->data);
    INORDER(root->right);
}
void PREORDER(struct node* root)
{
    if(root == NULL){
        return;
    }
    printf("%c",root->data);
    PREORDER(root->left);
    PREORDER(root->right);
}
void POSTORDER(struct node* root)
{
    if(root == NULL){
        return;
    }
    POSTORDER(root->left);
    POSTORDER(root->right);
    printf("%c",root->data);
}
int main()
{
    struct node *root = createNode('A');
    root->left = createNode('B');
    root->left->right = createNode('E');
    root->left->left = createNode('D');
    root->right = createNode('C');
    printf("INORDER : ");
    INORDER(root);
    printf("\nPREORDER : ");
    PREORDER(root);
    printf("\nPOSTORDER : ");
    POSTORDER(root);
}
