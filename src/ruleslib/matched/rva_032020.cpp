struct MyStruct {
    static void __stdcall setWord(unsigned int ptr, unsigned short val);
};

void MyStruct::setWord(unsigned int ptr, unsigned short val) {
    *(unsigned short*)((char*)ptr + 0x5A) = val;
}

