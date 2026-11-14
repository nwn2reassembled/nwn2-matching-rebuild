struct MyClass {
    char pad1[80];
    unsigned char* base;
    char pad2[4];
    unsigned int limit;
    void setZeroAtIndex(unsigned short idx);
};

void MyClass::setZeroAtIndex(unsigned short idx) {
    if ((int)idx < (int)limit)
        base[idx] = 0;
}
