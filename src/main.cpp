#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

int main()
{
    node* node_50 = CreateNode (50);
    node* node_30 = CreateNode (30);
    node* node_10 = CreateNode (10);
    node* node_70 = CreateNode (70);
    node* node_65 = CreateNode (65);
    node* node_80 = CreateNode (80);
    node* node_66 = CreateNode (66);

    node_50->left  = node_30;
    node_30->left  = node_10;
    node_50->right = node_70;
    node_70->left  = node_65;
    node_70->right = node_80;
    node_65->right = node_66;

    Print (node_50);

    free (node_50);
    free (node_30);
    free (node_10);
    free (node_70);
    free (node_65);
    free (node_80);
    free (node_66);
}
