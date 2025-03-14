#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "Item.h"

static int currListSize = 0;
static int listSizeLimit = 0;
static int itemSizeLimit = 0;
static void* list = NULL;
static Item* head = NULL;


void MyDLLInit(int listSizeLim, uint16_t itemSizeLim) {
    currListSize = 0;
    listSizeLimit = listSizeLim;
    itemSizeLimit = itemSizeLim;

    //  Allocate memory for the entire list size
    list = malloc(listSizeLimit * itemSizeLimit);


    if (!list) {
        printf("     -> ERROR: List memory allocation did not succeed!\n");
        exit(EXIT_FAILURE);
    }

}

int MyDLLInsert(uint16_t key, unsigned char* data, uint16_t dataSize) {

    if (currListSize + 1 > listSizeLimit) {
        printf("     -> ERROR: Maximum array size reached! Item not added.\n");
        return 1;
    }

    if (dataSize > itemSizeLimit) {
        printf("     -> ERROR: Item is too large to be added! Item not added.\n");
        printf("%d - ", dataSize);
        printf("%d", itemSizeLimit);
        return 1;
    }

    Item* newItem = (Item*) malloc(sizeof(Item) + dataSize);
    if (!newItem)  {
        printf("     -> ERROR: Item memory allocation did not succeed!\n");
        free(newItem);
        exit(EXIT_FAILURE);
    }

    newItem->key = key;
    newItem->dataSize = dataSize;
    newItem->prev = newItem->next = NULL;

    memcpy(newItem->data, data, dataSize);

    //  If the list is not empty, go through it and get the last Item
    if (currListSize != 0) {
        Item* temp = head;
        Item* last = head;

        while (temp) {
            //printf("[Key: %u] %s <-> ", temp->key, temp->data);
            last = temp;
            temp = temp->next;
        }

        last->next = newItem;
        newItem->prev = last;
    }
    //  Else, this item is the head
    else {
        head = newItem;
    }

    currListSize++;
    //printf("    -> New list size: %2d\n", currListSize);

    return 0;
}

int MyDLLRemove(uint16_t key) {

}

int MyDLLFind(uint16_t key) {

}

int MyDLLFindNext(uint16_t key) {

}

int MyDLLFindPrevious(uint16_t key) {

}

int MyDLLPrint() {

    printf("    Key | Data Size | Data \n");
    printf(" -------+-----------+----");

    for (int i = 0; i < itemSizeLimit; i++) {
        printf("-");
    }
    printf("\n");

    if (currListSize != 0) {
        Item* temp = head;

        while (temp) {
            printf(" %6u | %9d | %-*s\n", temp->key, temp->dataSize, itemSizeLimit, temp->data);
            
            temp = temp->next;
        }

    }
}