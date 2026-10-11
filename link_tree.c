#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* create_node(int value)
{
    TreeNode*p=(TreeNode*)malloc(sizeof(TreeNode));
    if(p==NULL)
    {
        return NULL;
    }
    p->data=value;
    p->left=NULL;
    p->right=NULL;

    return p;

}

void preorder(TreeNode*root)//前序遍历
{
    if(root==NULL)
    {
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode*root)//中序遍历
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

void postorder(TreeNode*root)//后序遍历
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

int depth(TreeNode* root,int current_depth,int max_depth)
{
    if(root==NULL)
    {
        if(current_depth>max_depth)
        {
            return current_depth;
        }
        else
        {
            return max_depth;
        }
    }
    int left_max=depth(root->left,current_depth+1,max_depth);
    int right_max=depth(root->right,current_depth+1,max_depth);
    if(left_max>right_max)
    {
        return left_max;
    }
    else{
        return right_max;
    }


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


    // printf("前序：");preorder(root);printf("\n");
    // printf("中序：");inorder(root);printf("\n");
    // printf("后序：");postorder(root);printf("\n");

    int tree_depth=depth(root,0,0);
    printf("树的深度是:%d\n",tree_depth);

    return 0;


}
