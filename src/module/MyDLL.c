#include <stdio.h>
#include "person.h"

static int currSize = 0;
static int maxSize = 0;

void MyDLLInit(int mSize) {
    currSize = 0;
    maxSize = mSize;
}

bool MyDLLInsert() {

    if (currSize + 1 > maxSize) {
        printf(" - ERROR: Maximum array size reached.\n");
        return false;
    }

    currSize += 1;
    printf("Curr size: " + currSize);
}