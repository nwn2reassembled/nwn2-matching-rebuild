class MyClass {
public:
    char pad1[0x180];
    int fieldRead;
    char pad2[0xc78]; // pads to offset 0xDFc
    float fieldFloat; // at offset 0xDFc
    int fieldCopy;    // at offset 0xE00
    void method();
};

void MyClass::method() {
    fieldFloat = 1.0f;
    fieldCopy = fieldRead;
}

