struct MyStruct {
    unsigned char data[168];
    unsigned int field;
    void setField(unsigned int value);
};

void MyStruct::setField(unsigned int value) {
    field = value;
}

