/** \file tests.c
*   \brief Main test file for the MyDLL module
*
*        This file tests all the funtions on the 
*       MyDLL module developped for this class
*
* \author Pedro Ramos 
* \author Rafael Morgado
* \date 11/3/2025
*/

#include <stdio.h>
#include <stdint.h>
#include "module/MyDLL.h"


int main(void) {
    



    printf("\n - == === Testing initialization === == -\n");

    int listSizeLimit = 5;
    uint16_t itemSizeLimit = 20;
    
    MyDLLInit(listSizeLimit, itemSizeLimit);
    printf(" - List initialized successfully!\n");
    




    printf("\n - == === Testing adding values === == -\n");


    uint16_t key1 = 1001;
    unsigned char data1[] = "TestData1";

    if (MyDLLInsert(key1, data1, sizeof(data1)) == 0) {
        printf(" - Item 1 inserted successfully!\n");
    } 
    else {
        printf(" - Item 1 insertion failed!\n");
    }
    

    uint16_t key2 = 1002;
    unsigned char data2[] = "TestData2";
    
    if (MyDLLInsert(key2, data2, sizeof(data2)) == 0) {
        printf(" - Item 2 inserted successfully!\n");
    } 
    else {
        printf(" - Item 2 insertion failed!\n");
    }
    

    uint16_t key3 = 1003;
    unsigned char data3[] = "TestData3";
    
    if (MyDLLInsert(key3, data3, sizeof(data3)) == 0) {
        printf(" - Item 3 inserted successfully!\n");
    } 
    else {
        printf(" - Item 3 insertion failed!\n");
    }
    



    printf("\n - == === Testing printing === == -\n");
    MyDLLPrint();




    printf("\n - == === Testing search === == -\n");
    unsigned char* foundData;

    foundData = MyDLLFind(key2);
    if (foundData != NULL) {
        printf(" - Data with key %u found successfully: %s!\n", key2, foundData);
    } 
    else {
        printf(" - Data with key %u not found\n", key2);
    }

    foundData = MyDLLFindNext();
    if (foundData != NULL) {
        printf(" - Next item is: %s!\n", foundData);
    } 
    else {
        printf(" - No next item in list\n");
    }

    foundData = MyDLLFindNext();
    if (foundData != NULL) {
        printf(" - Next item is: %s!\n", foundData);
    } 
    else {
        printf(" - No next item in list\n");
    }

    foundData = MyDLLFindPrevious();
    if (foundData != NULL) {
        printf(" - Previous item is: %s!\n", foundData);
    } 
    else {
        printf(" - No previous item in list\n");
    }

    foundData = MyDLLFindPrevious();
    if (foundData != NULL) {
        printf(" - Previous item is: %s!\n", foundData);
    } 
    else {
        printf(" - No previous item in list\n");
    }

    foundData = MyDLLFindPrevious();
    if (foundData != NULL) {
        printf(" - Previous item is: %s!\n", foundData);
    } 
    else {
        printf(" - No previous item in list\n");
    }




    printf("\n - == === Testing removing items === == -\n");

    if (MyDLLRemove(key2) == 0) {
        printf(" - Item 2 removed successfully!\n");
    } 
    else {
        printf(" - Item 2 removal failed (key %d not found)!\n", key2);
    }

    printf("   Current list:\n");
    MyDLLPrint();
    printf("\n");

    if (MyDLLRemove(key3) == 0) {
        printf(" - Item 3 removed successfully!\n");
    } 
    else {
        printf(" - Item 3 removal failed (key %d not found)!\n", key3);
    }

    printf("   Current list:\n");
    MyDLLPrint();
    printf("\n");

    if (MyDLLRemove(key1) == 0) {
        printf(" - Item 1 removed successfully!\n");
    } 
    else {
        printf(" - Item 1 removal failed (key %d not found)!\n", key1);
    }

    printf("   Current list:\n");
    MyDLLPrint();
    printf("\n");

    // Try to remove an item inexistente
    uint16_t key4 = 1004;
    if (MyDLLRemove(key4) == 0) {
        printf(" - Item 4 removed successfully!\n");
    } 
    else {
        printf(" - Item 4 removal failed (key %d not found)!\n", key4);
    }




    printf("\n - == === List state === == -\n");
    MyDLLPrint();

    
    return 0;
}