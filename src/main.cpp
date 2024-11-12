#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    Insert (node_50, 90);
    Insert (node_50, 35);
    Insert (node_50, 17);
    Insert (node_50, 42);

    PrintDot (node_50);
    DtorNode (node_50);
}
