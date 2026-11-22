struct MyClass {
    char padding[0x23c0];
    int flag;
    void setFlag();
};

void MyClass::setFlag() {
    flag = 1;
}

