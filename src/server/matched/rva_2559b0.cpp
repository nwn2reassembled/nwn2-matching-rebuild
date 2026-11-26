struct MyStruct {
    char pad[20];
    unsigned int field1;
    unsigned int field2;
    void setFields(unsigned int a, unsigned int b);
};

void MyStruct::setFields(unsigned int a, unsigned int b) {
    field1 = a;
    field2 = b;
}

