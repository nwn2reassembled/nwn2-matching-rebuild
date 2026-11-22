class MyClass {
public:
    void CopyFloats(const float* src);
private:
    char padding[0x508]; // pad to reach offset 0x508
    float field1;        // stored at this+0x508
    float field2;        // stored at this+0x50c
    float field3;        // stored at this+0x510
};

void MyClass::CopyFloats(const float* src) {
    field1 = src[0];
    field2 = src[1];
    field3 = src[2];
}

