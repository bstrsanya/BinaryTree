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
    assert (node);
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

void CreateDot (Node_t* node, FILE* file_dot)
{
    if (!node) return;

    fprintf (file_dot, "node%p [shape=record; style = filled; fillcolor = \"#ffe4c4\"; color = \"#800000\"; label = \"{data = %d | address = %p | { <f0> left = %p | <f1> right = %p}}\"];\n", node, node->data, node, node->left, node->right);

    if (node->left) 
    {
        fprintf (file_dot, "node%p: <f0> -> node%p [color = red, style = bold, arrowhead = vee];\n", node, node->left);
        CreateDot (node->left, file_dot);
    }
    if (node->right) 
    {
        fprintf (file_dot, "node%p: <f1> -> node%p [color = red, style = bold, arrowhead = vee];\n", node, node->right);
        CreateDot (node->right, file_dot);
    }
}

void PrintDot (Node_t* node)
{
    FILE* file_dot = fopen ("./aaa.dot", "w");
    assert (file_dot != NULL);
    fprintf (file_dot, "digraph{\nsplines=\"ortho\";\n");
    CreateDot (node, file_dot);
    fprintf (file_dot, "}");
    fclose (file_dot);
    system ("dot ./aaa.dot -Tpng -o ./aaa.png");
}