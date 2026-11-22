struct MyStruct {
    char pad[0xC7C];
    int value;
    int clearValue();
};

int MyStruct::clearValue() {
    value = 0;
    return 0;
}
