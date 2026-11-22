struct MyStruct {
    int a;
    int b;
    int c;
    int d;
    int e;          // offsets 0x00‑0x10
    int value;      // offset 0x14 – the field returned by the function
    int getValue() const;
};

int MyStruct::getValue() const { return value; }

