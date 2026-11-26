class MyClass {
public:
    void setFlag();
private:
    char pad[0x754];
    unsigned char flag;
};

void MyClass::setFlag() { flag = 1; }

