#pragma once
#ifndef COMPPRO_UTILITY_H
#define COMPPRO_UTILITY_H

#endif //COMPPRO_UTILITY_H
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    string type;
    int leafdata;
    int ldata;
    int rdata;
    struct Node* parent;
    struct Node* left;
    struct Node* center;
    struct Node* right;

}node;

node* makeNode(string typ){
    node* n = new node();
    n->type = typ;
    n->ldata = -1;
    n->rdata = -1;
    n->left = n->right = n->center = n->parent = nullptr;
    return n;
}



node* twoNode(int m, node* n1, node* n2){
    node* r = makeNode("TwoNode");
    r->left = n1;
    r->center = n2;
    r->ldata = m;
    n1->parent = r; n2->parent = r;
    return r;
}

node* threeNode(int m1, int m2, node* n1, node* n2, node* n3){
    node* r = makeNode("ThreeNode");
    r->ldata = m1; r->rdata = m2;
    r->left = n1; r->center = n2; r->right = n3;
    n1->parent = n2->parent = n3->parent = r;
    return r;
}
int findHeight(node* root){
    int height = 0;
    while(root != nullptr){
        height++;
        root = root->left;
    }

    return height;
}
int findMin(node* n){
    while(n->type != "Leaf"){
        n = n->left;
    }
    return n->leafdata;
}