struct MyStruct {
    int dummy;
    int value;
    int compute() const;
};

int MyStruct::compute() const {
    return value + 0x210;
}

