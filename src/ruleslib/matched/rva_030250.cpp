struct MyStruct {
    unsigned int dummy; // ordinary data member
    static void __stdcall setValue(unsigned int *ptr, unsigned short val);
};

void MyStruct::setValue(unsigned int *ptr, unsigned short val) {
    *(unsigned short*)((char*)ptr + 0x64) = val;
}

