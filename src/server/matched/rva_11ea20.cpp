struct MyStruct {
    int pad0[16];
    int value;
    int getValue();
};

int MyStruct::getValue() { return value; }
