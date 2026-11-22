class MyClass {
public:
    void setFlag();
private:
    char padding[168];
    int flag;
};

void MyClass::setFlag() { flag = 1; }
