struct MyStruct {
    char pad[80];
    int value;

    int getValue() const;
};

int MyStruct::getValue() const { return value; }
