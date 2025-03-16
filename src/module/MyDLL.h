#include <stdint.h>

void MyDLLInit(int listSizeLimit, uint16_t itemSizeLimit);

int MyDLLInsert(uint16_t key, unsigned char* data, uint16_t dataSize);

int MyDLLRemove(uint16_t key);

unsigned char* MyDLLFind(uint16_t key);

unsigned char* MyDLLFindNext();

unsigned char* MyDLLFindPrevious();

int MyDLLPrint();