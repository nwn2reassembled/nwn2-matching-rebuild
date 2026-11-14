struct MyStruct {
    int first;
    unsigned char second;
    char pad1[163];
    int data[106];

    MyStruct* clear();
};

MyStruct* MyStruct::clear() {
    this->first = 0;
    this->second = 0;
    for (int i = 0; i < 106; ++i) {
        data[i] = 0;
    }
    return this;
}
