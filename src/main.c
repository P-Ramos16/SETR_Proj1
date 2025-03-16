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
    printf("7 - Exit        |\n");
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
                data[strcspn((char*)data, "\n")] = 0; // Remove o ENTER
                
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
                
                if (MyDLLRemove(key) == 0) {
                    printf(" - Item removed successfully!\n");
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
                printf("\nNÃO FEITO");
                break;
            
            case 6:
                printf("\nNÃO FEITO");
                break;

            case 7:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid option! Try again.\n");
                getchar(); 
        }
    } while (option != 7);
    return 0;
} 