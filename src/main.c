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
#include "module/Person.h"
#include "module/MyDLL.h"


int main(void) {
    
    printf(" - == === Testing initialization === == -\n");
    MyDLLInit(4); // Imicializa a lista com mSize=4
    printf("    -> OK\n\n");
    
    printf(" - == === Testing adding values === == -\n");
    
    /*Person prs;
    strcpy(prs.first_name, "John");
    strcpy(prs.last_name, "Doe");
    prs.number = 1;

    for (int i = 0; i < 6; i++) {
        MyDLLInsert(prs);
    }*/

    return 0;
}