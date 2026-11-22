struct MyStruct {
    int dummy;
    int addConst(int value);
};

int MyStruct::addConst(int value) { return value + 0x278; }
