class Legacy{public: unsigned char getByte(void* ptr);}; unsigned char Legacy::getByte(void* ptr){unsigned char*p=(unsigned char*)ptr;return *(p+0x78);}
