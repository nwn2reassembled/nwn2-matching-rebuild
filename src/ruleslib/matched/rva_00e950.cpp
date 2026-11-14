struct MyClass {
    char pad[108];
    unsigned int* table;
    int count;
    unsigned int getValue(unsigned char idx) const;
};

unsigned int MyClass::getValue(unsigned char idx) const {
    if (idx >= count)
        return 0;
    return table[idx];
}
