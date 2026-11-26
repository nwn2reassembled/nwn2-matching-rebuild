struct MyStruct {
    // Pad to reach offset 0x28 (40 decimal)
    char pad[40];
    int fieldA;   // offset 0x28
    int fieldB;   // offset 0x2c
    int fieldC;   // offset 0x30
    int fieldD;   // offset 0x34

    void setValues(int a, int b);
};

void MyStruct::setValues(int a, int b) {
    this->fieldA = a;
    this->fieldB = b;
    this->fieldC = 10000000; // 0x989680
    this->fieldD = 0;
}

