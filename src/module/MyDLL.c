#include <stdio.h>
#include "Person.h"

static int currSize = 0;
static int maxSize = 0;

void MyDLLInit(int mSize) {
    currSize = 0;
    maxSize = mSize;
}

int MyDLLInsert() {

    if (currSize + 1 > maxSize) {
        printf(" - ERROR: Maximum array size reached.\n");
        return 1;
    }

    currSize += 1;
    printf("Curr size: %2d\n", currSize);

    return 0;
}