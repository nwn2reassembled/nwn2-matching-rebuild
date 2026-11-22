struct MyStruct {
    unsigned char data[0x2370];
    unsigned char field;
    void setField(unsigned char);
};

void MyStruct::setField(unsigned char val) { this->field = val; }
