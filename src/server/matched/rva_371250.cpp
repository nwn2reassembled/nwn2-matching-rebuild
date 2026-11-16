struct MyStruct {
    int field1;
    char field2;
    unsigned char pad[160];
    unsigned int array[106];
    MyStruct* clear();
};

MyStruct* MyStruct::clear() {
    this->field1 = 0;
    this->field2 = 0;
    for (unsigned int i=0; i<106; ++i)
        this->array[i] = 0;
    return this;
}

