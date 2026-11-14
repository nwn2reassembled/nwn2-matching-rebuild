struct MyClass {
    int placeholder1;
    int placeholder2;
    unsigned short table[27];
    int checkIndex(unsigned int idx);
};

int MyClass::checkIndex(unsigned int idx) {
    unsigned short value;
    if (idx <= 0x1a)
        value = table[idx];
    else
        value = 0xffff;
    return value != 0xffff;
}
