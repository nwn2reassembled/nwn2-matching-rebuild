struct MyClass {
    void setZeroAtOffset(int* ptr);
};

void MyClass::setZeroAtOffset(int* ptr) {
    ptr[16] = 0;
}
