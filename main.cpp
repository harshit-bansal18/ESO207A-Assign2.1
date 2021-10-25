//2-3 Trees
#pragma once
#include "Extract.h"
#include "Merge.h"
#include "MakeSingleton.h"
using namespace std;
#define ll long long
#define mt make_tuple
#define pb push_back

void Test(){
    //Testing code
    node* T = makeSingleton(1);
    for(int i = 2; i <=500; i++){
        T = Merge(T, makeSingleton(i));
    }
    node* U = makeSingleton(777);
    for(int i = 778; i <= 1000; i++)
        U = Merge(U, makeSingleton(i));
    node* V = Merge(T, U);
    Extract(V);

}

int main(){
    Test();

}

