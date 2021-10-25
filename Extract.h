#pragma once
#ifndef COMPPRO_EXTRACT_H
#define COMPPRO_EXTRACT_H

#endif //COMPPRO_EXTRACT_H
#include "utility.h"
void Extract(node* root){
    if(root == nullptr)return;
    if(root->type == "Leaf")
        cout << root->leafdata << " ";

    Extract(root->left);
    Extract(root->center);
    Extract(root->right);
}