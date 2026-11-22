class Legacy{public:unsigned short getField(void* p);};
unsigned short Legacy::getField(void* p){return *(unsigned short*)((char*)p+0x18c);}
