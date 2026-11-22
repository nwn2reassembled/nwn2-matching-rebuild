struct MyClass {
    char padding[236];
    int flag;

    void setFlag();
};

void MyClass::setFlag() {
    this->flag = 1;
}

