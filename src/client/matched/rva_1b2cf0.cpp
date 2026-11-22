struct MyStruct {
    unsigned char pad[0x500];
    unsigned int field;
    void setField(unsigned int);
};

void MyStruct::setField(unsigned int value) { field = value; }

