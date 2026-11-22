struct MyStruct {
    char pad[0x358];
    int value;
    int getValue();
};

int MyStruct::getValue() { return value; }

