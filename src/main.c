/** \file main.c
*   \brief Main file for the MyDLL module
*
*        This file utilizes all the funtions on the 
*       MyDLL module developped for this class
*
* \author Pedro Ramos 
* \author Rafael Morgado
* \date 11/03/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "module/MyDLL.h"
// #include "module/Person.h"


void showMenu() {
    printf("\n====== MENU =====\n");
    printf("1 - Check list  |\n");
    printf("2 - Add item    |\n");
    printf("3 - Remove item |\n");
    printf("4 - Find item   |\n");
    printf("5 - Next item   |\n");
    printf("6 - Prev item   |\n");
    printf("7 - Edit item   |\n");    
    printf("8 - Clear list  |\n");
    printf("9 - Exit        |\n");
    printf("=================\n");
    printf("Choose an option: ");
}

 int main(void) {

    int listSizeLimit = 5;
    uint16_t itemSizeLimit = 20;
    
    MyDLLInit(listSizeLimit, itemSizeLimit);
    
    int option;
    uint16_t key;
    unsigned char data[itemSizeLimit];
    
    do {
        showMenu();
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                printf("\n - == Actual list == -\n");
                MyDLLPrint();
                getchar(); 
                break;

            case 2:
                printf("\nType the key (uint16_t): ");
                scanf("%hu", &key);
                getchar(); 
                
                printf("Type the data (max %d characters): ", itemSizeLimit - 1);
                fgets((char*)data, itemSizeLimit, stdin);
                data[strcspn((char*)data, "\n")] = 0;
                
                if (MyDLLInsert(key, data, strlen((char*)data) + 1) == 0) {
                    printf(" - Item inserted successfully!\n");
                } else {
                    printf(" - Error: Item insertion failed!.\n");
                }
                getchar(); 
                break;

            case 3:
                printf("\nEnter the key of the item to remove: ");
                scanf("%hu", &key);
                
                unsigned char* itemData = MyDLLFind(key);

                if (MyDLLRemove(key) == 0) {
                    printf(" - Item \"%s\" removed successfully!\n", itemData);
                    getchar();
                } else {
                    printf(" - Error: Item not found.\n");
                    getchar();
                }
                getchar(); 
                break;

            case 4:
                printf("\nEnter the key of the item to search for: ");
                scanf("%hu", &key);

                unsigned char* result = MyDLLFind(key);
                if (result != NULL) {
                    printf(" - Item found: %s\n", result);
                    getchar(); 
                } else {
                    printf(" - Erro: Item not found.\n");
                    getchar(); 
                }
                getchar(); 
                break;
            
            case 5:
                unsigned char* nextData = MyDLLFindNext();
                if (nextData != NULL) {
                    printf("\n - Next item: %s\n", nextData);
                } else {
                    printf("\n - No next item available.\n");
                }
                getchar();
                break;
            
            case 6:
                unsigned char* prevData = MyDLLFindPrevious();
                if (prevData != NULL) {
                    printf("\n - Previous item: %s\n", prevData);
                } else {
                    printf("\n - No previous item available.\n");
                }
                getchar();
                break;
                
            case 7:
                printf("\nEnter the key of the item to edit: ");
                scanf("%hu", &key);
                getchar();
            
                MyDLLEdit(key);
                getchar();                
                break;
            
            case 8:
                MyDLLClear();
                getchar();

            case 9:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid option! Try again.\n");
                getchar(); 
        }
    } while (option != 9);
    return 0;
} 