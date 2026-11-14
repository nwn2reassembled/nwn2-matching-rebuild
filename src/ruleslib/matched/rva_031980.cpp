struct OffStruct {
    char dummy[0x62a];
    unsigned char value;
};

class MyStruct {
public:
    static void __stdcall setByte(void* ptr, unsigned char value);
};

void MyStruct::setByte(void* ptr, unsigned char value) {
    reinterpret_cast<OffStruct*>(ptr)->value = value;
}

