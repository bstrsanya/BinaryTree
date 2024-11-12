#ifndef TREE_H
#define TREE_H

struct Node_t
{
    int data;
    Node_t* left;
    Node_t* right;
};

Node_t* CreateNode (int value);
void Print (Node_t* node);
void Insert (Node_t* node, int value);
void DtorNode (Node_t* node);
void CreateDot (Node_t* node, FILE* file);
void PrintDot (Node_t* node);

#endif