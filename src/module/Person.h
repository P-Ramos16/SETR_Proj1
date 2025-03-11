#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <string.h>

// Define a structure for a Person
typedef struct {
    char first_name[32];
    char last_name[32];
    int number;
} Person;

#endif // PERSON_H