/**
 * @file Item.h
 * @brief Defines the structure for items in the double linked list.
 *
 * \author Pedro Ramos, n.º 107348
 */
 
#ifndef ITEM_H
#define ITEM_H

#include <stdint.h>
#include <string.h>

/**
 * @struct Item
 * @brief Represents an item in the double linked list.
 *
 * This structure contains a unique key, data size, pointers to previous
 * and next items in the list, and a flexible array for data storage.
 */
// Define a structure for the list items
typedef struct Item {
    uint16_t key;         /**< Unique identifier for the item. */
    size_t dataSize;      /**< Size of the data stored in the item. */
    struct Item *prev;    /**< Pointer to the previous item in the list. */
    struct Item *next;    /**< Pointer to the next item in the list. */
    unsigned char data[]; /**< Flexible array for storing item data. */
} Item;

#endif