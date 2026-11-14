class Target {
public:
    static void __stdcall setByte(struct MyStruct* obj, unsigned char value);
};

struct MyStruct {
    char dummy[10];          // bytes 0x00–0x09
    unsigned char byteField; // byte at offset 0xa
};

void Target::setByte(MyStruct* obj, unsigned char value) {
    obj->byteField = value;
}
