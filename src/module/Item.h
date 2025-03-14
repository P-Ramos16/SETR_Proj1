#ifndef ITEM_H
#define ITEM_H

#include <stdint.h>
#include <string.h>

// Define a structure for the list items

typedef struct Item {
    uint16_t key;
    size_t dataSize;
    struct Item *prev, *next;
    unsigned char data[];
} Item;

#endif