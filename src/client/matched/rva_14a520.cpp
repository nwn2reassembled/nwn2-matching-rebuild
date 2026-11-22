struct MyClass {
    char pad[0x2c8];
    float field1;
    float field2;
    float field3;
    void copyFrom(const float* src);
};

void MyClass::copyFrom(const float* src) {
    field1 = src[0];
    field2 = src[1];
    field3 = src[2];
}

