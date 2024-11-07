#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "BinaryTree.h"

Node_t* CreateNode (int value)
{
    Node_t* new_node = (Node_t*) calloc (1, sizeof (Node_t));
    if (new_node == NULL) assert (0);

    new_node->data = value;

    return new_node;
}

void Print (Node_t* node)
{
    if (!node) return;
    
    printf ("(");

    if (node->left) Print (node->left);
    printf ("%d", node->data);
    if (node->right) Print (node->right);

    printf (")");
}

void DtorNode (Node_t* node)
{
    if (!node) return;
    
    if (node->left) DtorNode (node->left);
    if (node->right) DtorNode (node->right);

    free (node);
    node = NULL;
}

void Insert (Node_t* node, int value)
{
    assert (value);
    if (value < node->data)
        if (node->left != NULL)
            Insert (node->left, value);
        else
            node->left = CreateNode (value);
    else
        if (node->right != NULL)
            Insert (node->right, value);
        else
            node->right = CreateNode (value);          
}

void CreateDot (Node_t* node)
{
    if (!node) return;

    printf ("node%p [shape=Mrecord; style = filled; color = pink; label = \"{data = %d}\"];\n", node, node->data);

    if (node->left) 
    {
        CreateDot (node->left);
        printf ("node%p -> node%p [color = red, style = bold, arrowhead = vee];\n", node, node->left);
    }
    if (node->right) 
    {
        CreateDot (node->right);
        printf ("node%p -> node%p [color = red, style = bold, arrowhead = vee];\n", node, node->right);
    }

}