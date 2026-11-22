struct MyStruct {
    int dummy[24];
    int value;
    int getValue();
};

int MyStruct::getValue() {
    return value;
}

