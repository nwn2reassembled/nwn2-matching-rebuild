struct MyStruct {
    unsigned char data[0x5B];
};

class MyClass {
public:
    void setByte(MyStruct* p, unsigned char v);
};

void MyClass::setByte(MyStruct* p, unsigned char v) {
    *(unsigned char*)((char*)p + 0x5A) = v;
}

