class LegacyObject{public:int init();};

int LegacyObject::init(){
    *(int*)((char*)this+0x14)=0;
    *(int*)((char*)this+0x18)=0;
    *(int*)((char*)this+0x34)=0;
    *((short*)((char*)this+0xc))=0;
    *(int*)((char*)this+0x10)=0;
    *(int*)((char*)this+0x1c)=0;
    *(int*)((char*)this+0x20)=0;
    *(int*)((char*)this+0x24)=0;
    *(int*)((char*)this+0x28)=0;
    *((unsigned char*)((char*)this+0x30))=5;
    return 1;}

