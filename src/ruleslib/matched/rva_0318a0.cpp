struct MyStruct { unsigned char data[0x55]; };

class X {
public:
    unsigned char getField(MyStruct* p);
};

unsigned char X::getField(MyStruct* p) {
    return p->data[0x54];
}

