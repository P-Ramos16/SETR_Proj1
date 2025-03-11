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
#include "module/person.h"
#include "modult/MyDLL.h"


int main(void) {
    
    printf(" - == === Testing initialization === == -\n");
    MyDLLInit(4);
    printf("    -> OK\n\n");
    
    printf(" - == === Testing adding values === == -\n");

    Person prs;
    prs.first_name = "John";
    prs.last_name = "Doe";
    prs.last_name = 1;

    for (int i = 0; i < 5; i++) {
        MyDLLInsert(prs);
    }

    return 0;
}