#ifndef TREE_H
#define TREE_H

struct node
{
    int data;
    node* left;
    node* right;
};

node* CreateNode (int value);
void Print (node* node);

#endif