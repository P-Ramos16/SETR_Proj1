/** \file tests.c
*   \brief Main test file for the MyDLL module
*
*        This file tests all the funtions on the 
*       MyDLL module developped for this class
*
* \author Pedro Ramos, n.º 107348
* \author Rafael Morgado, n.º 104277
* \date 14/3/2025
*/

#include <stdio.h>
#include <stdint.h>
#include "module/MyDLL.h"


/**
 * @brief Main function to execute tests on the MyDLL module.
 * 
 * Initializes the list, inserts elements, prints them, searches, and removes items.
 *
 * @return Returns 0 upon successful execution.
 */
int main(void) {
    
    printf(" ╭───────────────────────────────────────────────╮\n");
    printf(" │                                               │\n");
    printf(" │  - == === DLL IMPLEMENTATION TESTS === == -   │\n");
    printf(" │                                               │\n");
    printf(" ╰───────────────────────────────────────────────╯\n\n");


    printf(" ╭───────────────────────────────────────────────╮\n");
    printf(" │             Testing initialization            │\n");
    printf(" ├───────────────────────────────────────────────┤\n");

    int listSizeLimit = 3;       /**< Maximum number of elements in the list. */
    uint16_t itemSizeLimit = 20; /**< Maximum size of an individual item. */
    
    MyDLLInit(listSizeLimit, itemSizeLimit);
    
    printf(" │  List initialized successfully with:          │\n");
    printf(" │   - Maximum list size: %2d                     │\n", listSizeLimit);
    printf(" │   - Maximum item size: %2d                     │\n", itemSizeLimit);
    printf(" ╰───────────────────────────────────────────────╯\n\n");
    



    /** @brief Inserts an item into the list. */
    printf(" ╭───────────────────────────────────────────────╮\n");
    printf(" │             Testing adding values             │\n");
    printf(" ╰───────────────────────────────────────────────╯\n\n");

    printf(" => Inserting 4 items\n");

    uint16_t key1 = 101;
    unsigned char data1[] = "TestData1";

    printf("    -Item 1: ");
    if (MyDLLInsert(key1, data1, sizeof(data1)) == 0) {
        printf("successfull {%u: %s}!\n", key1, data1);
    } 
    else {
        printf(" failed!\n");
    }
    

    uint16_t key2 = 12;
    unsigned char data2[] = "DB password";
    
    printf("    -Item 2: ");
    if (MyDLLInsert(key2, data2, sizeof(data2)) == 0) {
        printf("successfull {%u: %s}!\n", key2, data2);
    } 
    else {
        printf(" failed!\n");
    }
    

    uint16_t key6 = 14;
    unsigned char data6[] = "Important info that is too long";
    
    printf("    -Long item: ");
    if (MyDLLInsert(key6, data6, sizeof(data6)) == 0) {
        printf("successfull {%u: %s}!\n", key6, data6);
    } 
    else {
        printf(" failed!\n");
    }
    

    uint16_t key3 = 3;
    unsigned char data3[] = "Important info";
    
    printf("    -Item 3: ");
    if (MyDLLInsert(key3, data3, sizeof(data3)) == 0) {
        printf("successfull {%u: %s}!\n", key3, data3);
    } 
    else {
        printf(" failed!\n");
    }
    

    uint16_t key4 = 14;
    unsigned char data4[] = "Important info";
    
    printf("    -Item 4 (too many): ");
    if (MyDLLInsert(key4, data4, sizeof(data4)) == 0) {
        printf("successfull {%u: %s}!\n", key4, data4);
    } 
    else {
        printf(" failed!\n");
    }
    
    printf("\n");



    /** @brief Prints the current list state. */
    printf(" ╭───────────────────────────────────────────────╮\n");
    printf(" │               Testing printing                │\n");
    printf(" ╰───────────────────────────────────────────────╯\n");
    
    MyDLLPrint();



    /** @brief Searches for an item with a specific key. */
    printf("\n ╭───────────────────────────────────────────────╮\n");
    printf(" │                Testing search                 │\n");
    printf(" ╰───────────────────────────────────────────────╯\n");
    unsigned char* foundData;

    printf("    -Key 12: ");

    foundData = MyDLLFind(key2);
    if (foundData != NULL) {
        printf("Key '%u' found successfully: '%s'\n", key2, foundData);
    } 
    else {
        printf("Key %u not found\n", key2);
    }

    printf("    -Next item: ");

    foundData = MyDLLFindNext();
    if (foundData != NULL) {
        printf("Next item data is: '%s'\n", foundData);
    } 
    else {
        printf("No next item in list\n");
    }

    printf("    -Next item: ");
    
    foundData = MyDLLFindNext();
    if (foundData != NULL) {
        printf("Next item data is: '%s'\n", foundData);
    } 
    else {
        printf("No next item in list\n");
    }

    printf("    -Previous item: ");

    foundData = MyDLLFindPrevious();
    if (foundData != NULL) {
        printf("Previous item data is: '%s'\n", foundData);
    } 
    else {
        printf("No previous item in list\n");
    }

    printf("    -Previous item: ");

    foundData = MyDLLFindPrevious();
    if (foundData != NULL) {
        printf("Previous item data is: '%s'\n", foundData);
    } 
    else {
        printf("No previous item in list\n");
    }

    printf("    -Previous item: ");

    foundData = MyDLLFindPrevious();
    if (foundData != NULL) {
        printf("Previous item data is: '%s'\n", foundData);
    } 
    else {
        printf("No previous item in list\n");
    }



    /** @brief Removes an item from the list. */
    printf("\n ╭───────────────────────────────────────────────╮\n");
    printf(" │            Testing removing items             │\n");
    printf(" ╰───────────────────────────────────────────────╯\n");

    printf("    -Remove item with key %d: ", key2);
    if (MyDLLRemove(key2) == 0) {
        printf(" removed successfully!\n");
    } 
    else {
        printf(" removal failed (key %d not found)!\n", key2);
    }

    printf("   Current list:\n");
    MyDLLPrint();
    printf("\n");

    printf("    -Remove item with key %d: ", key3);
    if (MyDLLRemove(key3) == 0) {
        printf(" removed successfully!\n");
    } 
    else {
        printf(" removal failed (key %d not found)!\n", key3);
    }

    printf("   Current list:\n");
    MyDLLPrint();
    printf("\n");

    key4 = 104;
    printf("    -Remove item with key %d: ", key4);
    if (MyDLLRemove(key4) == 0) {
        printf(" removed successfully!\n");
    } 
    else {
        printf(" removal failed!\n", key4);
    }

    printf("    -Remove item with key %d: ", key1);
    if (MyDLLRemove(key1) == 0) {
        printf(" removed successfully!\n");
    } 
    else {
        printf(" removal failed!\n", key1);
    }

    printf("   Current list:\n");
    MyDLLPrint();
    printf("\n");

    uint16_t key5 = 1005;
    printf("    -Remove item with key %d: ", key5);
    if (MyDLLRemove(key5) == 0) {
        printf(" removed successfully!\n");
    } 
    else {
        printf(" removal failed!\n", key5);
    }



    /** @brief Final list state. */
    printf("\n ╭───────────────────────────────────────────────╮\n");
    printf(" │               Final List state                │\n");
    printf(" ╰───────────────────────────────────────────────╯\n");
    MyDLLPrint();

    
    return 0;
}