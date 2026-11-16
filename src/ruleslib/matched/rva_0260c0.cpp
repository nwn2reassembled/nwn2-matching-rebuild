struct MyStruct {
    unsigned char pad[0x130];
    unsigned long field_130;
    static unsigned long __stdcall getField(const MyStruct* thisPtr);
};

unsigned long MyStruct::getField(const MyStruct* thisPtr) { return thisPtr->field_130; }

