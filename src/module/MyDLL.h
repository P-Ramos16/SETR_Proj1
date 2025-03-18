/**
 * \file MyDLL.h
 * \brief Header file for the double linked list module.
 * 
 * This file contains function declarations for managing a double linked list.
 *
 * \author Pedro Ramos, n.º 107348
 * \date 11/3/2025
 */

 #ifndef MYDLL_H
 #define MYDLL_H
 
 #include <stdint.h>
 
 /**
  * \brief Initializes the double linked list.
  *
  * \param listSizeLimit Maximum number of items in the list.
  * \param itemSizeLimit Maximum size of each item in bytes.
  */
 void MyDLLInit(int listSizeLimit, uint16_t itemSizeLimit);
 
 /**
  * \brief Inserts an item into the double linked list.
  *
  * \param key Unique key identifier for the item.
  * \param data Pointer to the data to be inserted.
  * \param dataSize Size of the data in bytes.
  * \return 0 if successful, 1 if insertion failed.
  */
 int MyDLLInsert(uint16_t key, unsigned char* data, uint16_t dataSize);
 
 /**
  * \brief Removes an item from the double linked list by key.
  *
  * \param key Unique key identifier of the item to remove.
  * \return 0 if successful, 1 if the item was not found.
  */
 int MyDLLRemove(uint16_t key);
 
 /**
  * \brief Finds an item in the double linked list by key.
  *
  * \param key Unique key identifier of the item to find.
  * \return Pointer to the data if found, NULL otherwise.
  */
 unsigned char* MyDLLFind(uint16_t key);
 
 /**
  * \brief Finds the next item in the list.
  *
  * \return Pointer to the data of the next item, or NULL if at the end.
  */
 unsigned char* MyDLLFindNext();
 
 /**
  * \brief Finds the previous item in the list.
  *
  * \return Pointer to the data of the previous item, or NULL if at the start.
  */
 unsigned char* MyDLLFindPrevious();
 
 /**
  * \brief Prints all items in the list in a table format.
  *
  * \return 0 if successful, or an error code if printing fails.
  */
 int MyDLLPrint();

 /**
 * \brief Clears the entire double linked list, removing all items.
 */
void MyDLLClear();

/**
 * \brief Edits an existing item in the double linked list by removing and reinserting it.
 * 
 * \param key Unique key identifier of the item to edit.
 * 
 * \return 0 if successful, 1 if the item was not found or could not be reinserted.
 */
int MyDLLEdit(uint16_t key, unsigned char* data, uint16_t dataSize);
 
 #endif // MYDLL_H
 