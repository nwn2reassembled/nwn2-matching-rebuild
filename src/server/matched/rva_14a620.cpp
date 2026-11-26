struct MyStruct {
    unsigned int dummy;
    unsigned int * ptr;

    unsigned int getValue() const; // declared in class
};

unsigned int MyStruct::getValue() const {
    return *reinterpret_cast<const unsigned int*>(
        reinterpret_cast<const unsigned char*>(ptr) + 0x10080);
}

