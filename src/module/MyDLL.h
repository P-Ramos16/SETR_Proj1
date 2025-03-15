#include <stdint.h>

void MyDLLInit(int listSizeLimit, uint16_t itemSizeLimit);

int MyDLLInsert(uint16_t key, unsigned char* data, uint16_t dataSize);

int MyDLLRemove(uint16_t key);

unsigned char* MyDLLFind(uint16_t key);

int MyDLLFindNext(uint16_t key);

int MyDLLFindPrevious(uint16_t key);

int MyDLLPrint();