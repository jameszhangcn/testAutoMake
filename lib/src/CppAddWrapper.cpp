#include "CppAddWrapper.h"
#include <stdio.h>
#include "CppAdd.h"

#ifdef __cplusplus
extern "C" {
#endif

int cppaddwrapper(int x, int y) {
    printf("from wrapper. \n");
    int sum = cppadd(x,y);
    return sum;
}

#ifdef __cplusplus
}
#endif

