struct MyStruct {
    static void __stdcall setByteAtOffset(unsigned long ptr, unsigned char val);
};

void MyStruct::setByteAtOffset(unsigned long ptr, unsigned char val)
{
    reinterpret_cast<unsigned char*>(ptr)[0x62] = val;
}

