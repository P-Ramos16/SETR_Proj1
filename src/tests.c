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
    
    return 0;
}