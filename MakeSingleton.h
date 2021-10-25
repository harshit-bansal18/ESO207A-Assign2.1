#pragma once
#include "utility.h"
#ifndef COMPPRO_MAKESINGLETON_H
#define COMPPRO_MAKESINGLETON_H

#endif //COMPPRO_MAKESINGLETON_H

node* makeSingleton(int dat){
    node* l = makeNode("Leaf");
    l->leafdata = dat;
    return l;
}