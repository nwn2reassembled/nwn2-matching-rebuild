struct Other {
    unsigned char data[176];
    unsigned char flag;
};

struct MyClass {
    void* dummy;
    Other* ptr;
    void setFlag();
};

void MyClass::setFlag() {
    ptr->flag = 1;
}

