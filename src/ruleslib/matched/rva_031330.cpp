struct Legacy{int getValue(void* ptr);};

int Legacy::getValue(void* ptr){return *(int*)((char*)ptr+0x5b0);}
