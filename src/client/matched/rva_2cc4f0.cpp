struct MyStruct {
    int dummy;
    int value;

    int foo() const; // declaration
};

int MyStruct::foo() const {
    return value + 0x378;
}

