
#ifndef COMPPRO_MERGE_H
#define COMPPRO_MERGE_H

#endif //COMPPRO_MERGE_H
#include"utility.h"

node* insertTreeLeft(node* n1, node* n, int m){ // returns root of the merged tree
    // n1 = leftmost node of tree at some height in which we have to insert
    // n = root of tree(modified after recursive steps) we have to insert
    // m = minimum value of n1
    if(n1->parent == nullptr){ // If we reach root
        if(n== nullptr)return n1;
        if(n1->type == "TwoNode"){ // if root has 2 child add one more child to it and return it
            n1->type = "ThreeNode";
            n1->right = n1->center;
            n1->center = n1->left;
            n1->left = n;
            n1->rdata = n1->ldata;
            n1->ldata = m;
            n->parent = n1;

            return n1;
        }
        else if(n1->type == "ThreeNode"){ // if root has 3 child then break it and make new root with both
                                          // nodes as child
            int mn = n1->ldata;
            node* n2 = twoNode(m, n, n1->left);
            n1->type = "TwoNode";
            n1->left = n1->center;
            n1->center = n1->right;
            n1->right = nullptr;
            n1->ldata = n1->rdata;
            n1->rdata = -1;

            return twoNode(mn, n2, n1);

        }
    }

    if(n == nullptr)return insertTreeLeft(n1->parent, n, NULL); // if tree has already been inserted then traverse to root

    if(n1->type == "TwoNode"){ // if n1 has 2 child then insert tree here as left child
        n1->type = "ThreeNode";
        n1->right = n1->center;
        n1->center = n1->left;
        n1->left = n;
        n1->rdata = n1->ldata;
        n1->ldata = m;
        n->parent = n1;
        return insertTreeLeft(n1->parent, nullptr, NULL);
    }
    else if(n1->type == "ThreeNode"){ // if n1 has 3 child then break it into n1.center, n1.right and n, n1.left
        int mn = n1->ldata;
        node* n2 = twoNode(m, n, n1->left);
        n1->left = n1->center;
        n1->center = n1->right;
        n1->right = nullptr;
        n1->ldata = n1->rdata;
        n1->rdata = -1;
        return insertTreeLeft(n1->parent, n2, mn);
    }

}

node* insertTreeRight(node* n1, node* n, int minn){
    // n1 = rightmost node of tree at some height in which we have to insert tree
    // n = root of tree(modified after recursive calls) we have to insert
    // minn = minimum value of node n
    if(n1->parent == nullptr){ // if n1 is root of tree
        if(n == nullptr)return n1;
        if(n1->type == "TwoNode"){ // if root has 2 child then add tree as right child
            n1->type = "ThreeNode";
            n1->right = n;
            n1->rdata = minn;
            n->parent = n1;
            return n1;
        }
        else if(n1->type == "ThreeNode"){ // if root has 3 child then break it and make new root with n1 and n2 as child
            int mn = n1->rdata;
            node* n2 = twoNode(minn, n1->right, n);
            n1 = twoNode(n1->ldata, n1->left, n1->center);
            n1->type = "TwoNode";
            n1->rdata = -1;
            n1->right = nullptr;
            return twoNode(mn, n1, n2);
        }
    }
    if(n == nullptr)return insertTreeRight(n1->parent, nullptr, NULL); // if tree is already inserted then traverse to root

    if(n1->type == "TwoNode"){ // if n1 has 2 child
        //Add one more child to that node and update it
        n1->type = "ThreeNode";
        n1->right = n;
        n1->rdata = minn;
        n->parent = n1;
        return insertTreeRight(n1->parent, nullptr, NULL);
    }

    else if(n1->type == "ThreeNode"){ // if n1 has 3 child
        // Break that node and make 2 nodes from n, n1.child1, n1.child2, n1.child3
        int mn = n1->rdata;
        node* n2 = twoNode(minn, n1->right, n);

        n1->type = "TwoNode";
        n1->right = nullptr;
        n1->rdata = -1;
        return insertTreeRight(n1->parent, n2, mn);
    }
}

node* Merge(node* n1, node* n2){ // input is taken such that values in Tree with root n1 are smaller than
                                //that with root n2
    if(n1 == nullptr) // if tree 1 is null then return n2
        return n2;
    if(n2 == nullptr) // if tree 2 in null then return n1
        return n1;
    node* n;
    int h1 = findHeight(n1), h2 = findHeight(n2);
    int m2 = findMin(n2);
    node* r1 = n1; node* r2 = n2;
    if(h1 < h2){ // traverse down the larger tree upto height one more than the smaller one
        while(h2 != h1 + 1){
            r2 = r2->left;
            h2--;
        }
        n = insertTreeLeft(r2, n1, m2); // call to insert smaller tree to the left of larger one
    }
    else if(h1 > h2){
        while(h1 != h2 + 1){
            if(r1->type == "TwoNode")r1 = r1->center;
            else r1 = r1->right;
            h1--;
        }
        n = insertTreeRight(r1, n2, m2); // call to insert smaller tree to the right of larger one
    }
    else{ // if both trees are of same height then make both child of another new root and return it
        n = twoNode(m2 ,n1, n2);
    }
    return n;
}