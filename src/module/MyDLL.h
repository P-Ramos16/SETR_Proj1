void MyDLLInit(int maxSize, uint_16 maxSizeLimit);

int MyDLLInsert(uint_16 uuid, unsigned char* data, uint_16 size);

int MyDLLRemove(uint_16 uuid);

int MyDLLFind(uint_16 uuid);

int MyDLLFindNext(uint_16 uuid);

int MyDLLFindPrevious(uint_16 uuid);