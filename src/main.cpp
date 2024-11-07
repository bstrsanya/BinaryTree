#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

int main()
{
    Node_t* node_50 = CreateNode (50);

    Insert (node_50, 30);
    Insert (node_50, 10);
    Insert (node_50, 70);
    Insert (node_50, 65);
    Insert (node_50, 66);
    Insert (node_50, 80);

    Print (node_50);
    CreateDot (node_50);
    DtorNode (node_50);
}
