class MyClass {
public:
    char pad[0x214];
    int flag;
    void setFlag();
};

void MyClass::setFlag() { flag = 1; }
