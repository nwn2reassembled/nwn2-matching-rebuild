struct MyStruct {
    int field0;
    int field4;
    unsigned int compute(unsigned char param) const;
};

unsigned int MyStruct::compute(unsigned char param) const {
    if (!field4 || param >= field0)
        return 0;
    return (param * 92u) + static_cast<unsigned int>(field4);
}

