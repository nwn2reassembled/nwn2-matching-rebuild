struct MyStruct {
    char pad[0x184];
    unsigned int arrayBase;
    static unsigned int __stdcall func(MyStruct* obj, unsigned short index);
};

unsigned int __stdcall MyStruct::func(MyStruct* obj, unsigned short index) {
    return obj->arrayBase + (index * 8u);
}

