#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "Item.h"

static int currListSize = 0;
static int listSizeLimit = 0;
static int itemSizeLimit = 0;

static void* list = NULL;
static Item* head = NULL;
static Item* selectedItem = NULL;


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
    selectedItem = newItem;

    return 0;
}

int MyDLLRemove(uint16_t key) {
    
    if(head == NULL) {
        printf("     -> ERROR: List is empty! No item removed.\n");
        return 1;
    }

    // search for the item with the key
    Item* temp = head;

    while(temp != NULL && temp->key != key){
        temp = temp->next;
    }

    // if the item is not found
    if(temp == NULL){
        printf("     -> ERROR: Item with key %u not found!\n", key);
        return 1;
    }

    // if the item is the head
    if (temp == head){
        head = temp->next;
        
        if(head){
            head->prev = NULL;
        }
    }
    else {
        temp->prev->next = temp->next;
    }
    
    //  If it's not the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
        selectedItem = temp->next;
    }
    else {
        selectedItem = temp->prev;
    }

    free(temp);
    currListSize--;
    return 0;

}

unsigned char* MyDLLFind(uint16_t key) {
    
    if (head == NULL) {
        printf("     -> ERROR: List is empty! Cannot search.\n");
        return NULL;
    }

    Item* temp = head;

    // search for the item with the key
    while (temp != NULL) {
        if (temp->key == key) {
            selectedItem = temp;
            return temp->data;
        }

        temp = temp->next;
    }

    return NULL;
}


unsigned char* MyDLLFindNext() {

    if (head == NULL || selectedItem == NULL) {
        printf("     -> ERROR: List is empty! Cannot search.\n");
        return NULL;
    }


    // search for the item with the key
    if (selectedItem->next == NULL) {
        return NULL;
    }

    selectedItem = selectedItem->next;

    return selectedItem->data;
}

unsigned char* MyDLLFindPrevious() {

    if (head == NULL || selectedItem == NULL) {
        printf("     -> ERROR: List is empty! Cannot search.\n");
        return NULL;
    }


    // search for the item with the key
    if (selectedItem->prev == NULL) {
        return NULL;
    }

    selectedItem = selectedItem->prev;

    return selectedItem->data;
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