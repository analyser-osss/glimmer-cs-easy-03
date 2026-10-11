#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* create_node(int value) {
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    if (p == NULL) return NULL;
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

typedef struct Stack
{
    TreeNode**arr;
    int top;
    int capacity;
}Stack;

Stack*createStack(int capacity)
{
    Stack*stack=(Stack*)malloc(sizeof(Stack));
    stack->arr=(TreeNode**)malloc(sizeof(TreeNode*)*capacity);
    stack->top=-1;
    stack->capacity=capacity;
    return stack;
}

int isEmpty(Stack*stack)
{
    return stack->top==-1;
}

void push(Stack*stack,TreeNode*node)
{
    if(stack->top==stack->capacity-1)
    {
        return;
    }
    stack->arr[++stack->top]=node;
}

TreeNode*pop(Stack*stack)
{
    if(isEmpty(stack)) return NULL;
    return stack->arr[stack->top--];
}

void preorderTraversal(TreeNode*root)
{
    Stack *stack=createStack(100);
    push(stack,root);
    while(!isEmpty(stack))
    {
        TreeNode*p=pop(stack);
        printf("%d ",p->data);//p->data=(*p).data

        if(p->right!=NULL)
        {
            push(stack,p->right);
        }
        if(p->left!=NULL)
        {
            push(stack,p->left);
        }

    }
    free(stack->arr);
    free(stack);
}

int main()
{
    TreeNode*root=create_node(1);

    root->left=create_node(2);
    root->right=create_node(3);

    root->left->left=create_node(4);
    root->left->right=create_node(5);

    root->right->left=create_node(6);
    root->right->right=create_node(7);

    printf("非递归前序：");
    preorderTraversal(root);
    printf("\n");

    return 0;
}