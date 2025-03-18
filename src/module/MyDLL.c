/**
 * @file MyDLL.c
 * @brief Implementation of a double linked list (DLL) with various operations.
 * 
 * This file contains the actial implementation for the double linked list.
 *
 * \author Pedro Ramos, n.º 107348
 * \author Rafael Morgado, n.º 104277
 * \date 13/3/2025
 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "Item.h"

/** Current size of the list. */
static int currListSize = 0;
/** Maximum allowed size of the list. */
static int listSizeLimit = 0;
/** Maximum allowed size for an item. */
static int itemSizeLimit = 0;

static void* list = NULL; /**< Pointer to the allocated memory for the list. */
static Item* head = NULL; /**< Pointer to the head of the list. */
static Item* selectedItem = NULL; /**< Pointer to the currently selected item. */


unsigned char* MyDLLFind(uint16_t key);

/**
 * @brief Initializes the double linked list.
 *
 * @param listSizeLim Maximum number of items allowed in the list.
 * @param itemSizeLim Maximum size of an individual item.
 */
void MyDLLInit(int listSizeLim, uint16_t itemSizeLim) {
    currListSize = 0;
    listSizeLimit = listSizeLim;
    itemSizeLimit = itemSizeLim;

    //  Allocate memory for the entire list size
    list = malloc(listSizeLimit * itemSizeLimit);


    if (!list) {
        printf("ERROR: List memory allocation did not succeed!");
        exit(EXIT_FAILURE);
    }

}


/**
 * @brief Inserts a new item into the list.
 *
 * @param key Unique identifier for the item.
 * @param data Pointer to the item's data.
 * @param dataSize Size of the item's data.
 * @return 0 on success, 1 on failure.
 */
int MyDLLInsert(uint16_t key, unsigned char* data, uint16_t dataSize) {

    if (currListSize + 1 > listSizeLimit) {
        printf("ERROR: Maximum array size reached! Item not added.");
        return 1;
    }

    if (dataSize > itemSizeLimit) {
        printf("ERROR: Item is too large to be added! Item not added.");
        return 1;
    }

    if (MyDLLFind(key) != NULL) {
        printf("ERROR: Item key is not unique! Item not added.");
        return 1;
    }


    Item* newItem = (Item*) malloc(sizeof(Item) + dataSize);
    if (!newItem)  {
        printf("ERROR: Item memory allocation did not succeed!");
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


/**
 * @brief Removes an item from the list.
 *
 * @param key Unique identifier for the item to be removed.
 * @return 0 on success, 1 if the item was not found.
 */
int MyDLLRemove(uint16_t key) {
    
    if(head == NULL) {
        printf("ERROR: List is empty! No item removed.");
        return 1;
    }

    // search for the item with the key
    Item* temp = head;

    while(temp != NULL && temp->key != key){
        temp = temp->next;
    }

    // if the item is not found
    if(temp == NULL){
        printf("ERROR: Item with key %u not found!", key);
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


/**
 * @brief Finds an item in the list by key.
 *
 * @param key Unique identifier for the item to find.
 * @return Pointer to the item's data if found, NULL otherwise.
 */
unsigned char* MyDLLFind(uint16_t key) {
    
    if (head == NULL) {
        //  ERROR: List is empty! Cannot search.
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


/**
 * @brief Finds the next item in the list.
 *
 * @return Pointer to the next item's data if available, NULL otherwise.
 */
unsigned char* MyDLLFindNext() {

    if (head == NULL || selectedItem == NULL) {
        printf("ERROR: List is empty! Cannot search.");
        return NULL;
    }


    // search for the item with the key
    if (selectedItem->next == NULL) {
        return NULL;
    }

    selectedItem = selectedItem->next;

    return selectedItem->data;
}


/**
 * @brief Finds the previous item in the list.
 *
 * @return Pointer to the previous item's data if available, NULL otherwise.
 */
unsigned char* MyDLLFindPrevious() {

    if (head == NULL || selectedItem == NULL) {
        printf("ERROR: List is empty! Cannot search.");
        return NULL;
    }


    // search for the item with the key
    if (selectedItem->prev == NULL) {
        return NULL;
    }

    selectedItem = selectedItem->prev;

    return selectedItem->data;
}

/**
 * @brief Prints the contents of the list in a formatted table.
 */
int MyDLLPrint() {

    printf(   " ╭───────┬───────────┬");

    for (int i = 0; i < itemSizeLimit; i++) printf("─");
    
    printf("╮\n │  Key  │ Data Size │ Data");
    for (int i = 0; i < itemSizeLimit-5; i++) printf(" ");
    printf("│\n ├───────┼───────────┼");

    for (int i = 0; i < itemSizeLimit; i++) printf("─");

    printf("┤\n");

    if (currListSize != 0) {
        Item* temp = head;

        while (temp) {
            printf(" │ %5u │ %9d │ %-*s│\n", temp->key, temp->dataSize, itemSizeLimit-1, temp->data);
            
            temp = temp->next;
        }

    }

    printf(" ╰───────┴───────────┴");
    for (int i = 0; i < itemSizeLimit; i++) printf("─");
    printf("╯\n");
}

/**
 * @brief Removes all items from the list, effectively clearing it.
 */
void MyDLLClear() {
    while (head != NULL) {
        MyDLLRemove(head->key);
    }
    printf(" - List cleared successfully!\n");
}

/**
 * @brief Edits an existing item in the double linked list by removing and reinserting it.
 * 
 * @param key Unique key identifier of the item to edit.
 * 
 * @return 0 if successful, 1 if the item was not found.
 */
int MyDLLEdit(uint16_t key) {

    unsigned char* oldData = MyDLLFind(key);   
    if (oldData == NULL) {
        printf(" - Error: Item not found. Cannot edit.\n");
        return 1;
    }
    
    // Remove
    uint16_t oldDataSize = strlen((char*)oldData) + 1;
    if (MyDLLRemove(key) != 0) {
        printf(" - Error: Could not remove item for editing.\n");
        return 1;
    }

    // Ask for new data
    unsigned char newData[itemSizeLimit];
    printf("Enter new data (max %d characters): ", itemSizeLimit - 1);
    fgets((char*)newData, itemSizeLimit, stdin);
    newData[strcspn((char*)newData, "\n")] = 0;

    // Reinsert
    if (MyDLLInsert(key, newData, strlen((char*)newData) + 1) == 0) {
        printf(" - Item edited successfully!\n");
        return 0;
    } else {
        printf(" - Error: Could not reinsert item after editing.\n");
        return 1;
    }
}


