#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100

typedef struct {
    int data;
    bool used;
} SeqTreeNode;

typedef struct {
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;

void init_tree(SeqBiTree*tree)
{
    for(int i=0;i<MAX_TREE_SIZE;i++)
    {
        tree->nodes[i].used=false;
    }
    tree->size=0;
}

bool set_root(SeqBiTree*tree,int value)
{
    tree->nodes[1].data=value;
    tree->nodes[1].used=true;
    if(tree->size<1)
    {
        tree->size=1;
    }
    return true;
}

bool  set_left_child(SeqBiTree*tree,int parent_node,int value)
{
    int left_index=2* parent_node;
    if(left_index>=MAX_TREE_SIZE)
    {
        return false;
    }
    tree->nodes[left_index].data=value;
    tree->nodes[left_index].used=true;

    tree->size++;
    return true;

}

bool  set_right_child(SeqBiTree*tree,int parent_node,int value)
{
    int right_index=2* parent_node+1;
    if(right_index>=MAX_TREE_SIZE)
    {
        return false;
    }
    tree->nodes[right_index].data=value;
    tree->nodes[right_index].used=true;

    tree->size++;
    return true;

}

void level_order(SeqBiTree*tree)
{
    if(tree->size==0)
    {
        return;
    }
    int next_level=2;
    for(int i=1;i<=tree->size;i++)
    {
        if(tree->nodes[i].used)
        {
            printf("%d ",tree->nodes[i].data);
        }
        else
        {
            printf("-1");
        }
        if(i==next_level-1)
        {
            printf("\n");
            next_level=next_level*2;
        }
    }
}

int main()
{
    SeqBiTree tree;
    init_tree(&tree);
    set_root(&tree,1);
    set_left_child(&tree,1,2);
    set_right_child(&tree,1,3);
    set_left_child(&tree,2,4);
    set_right_child(&tree,2,5);
    set_left_child(&tree,3,6);
    set_right_child(&tree,3,7);

    printf("遍历结果：\n");
    level_order(&tree);

    return 0;
}