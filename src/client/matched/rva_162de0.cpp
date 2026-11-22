struct MyStruct {
    char pad1[0x168];
    int b;
    int dummy;
    int a;
    int sum() const;
};

int MyStruct::sum() const { return a + b; }

