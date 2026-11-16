struct MyStruct {
    char padding[20];
    int value;
    int getValue() const;
};

int MyStruct::getValue() const { return value; }
