class MyStruct {
public:
    unsigned char pad[38];
    unsigned short value;
    static unsigned short __stdcall getField(const MyStruct* obj);
};

unsigned short MyStruct::getField(const MyStruct* obj) {
    return obj->value;
}

