#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "BinaryTree.h"

node* CreateNode (int value)
{
    node* new_node = (node*) calloc (1, sizeof (node));
    if (new_node == NULL) assert (0);

    new_node->data = value;

    return new_node;
}

void Print (node* node)
{
    if (!node) return;
    
    printf ("(");
    printf ("%d", node->data);

    if (node->left) Print (node->left);
    if (node->right) Print (node->right);

    printf (")");
}

