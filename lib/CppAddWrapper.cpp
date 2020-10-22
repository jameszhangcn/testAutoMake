#include "CppAddWrapper.h"
#include <stdio.h>
#include "CppAdd.h"

int cppaddwrapper(int x, int y) {
    printf("from wrapper. \n");
    int sum = cppadd(x,y);
    return sum;
}