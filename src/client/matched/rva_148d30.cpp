class MyClass {
public:
    virtual ~MyClass() {}
    void setValue(int);
private:
    int* target;
};

void MyClass::setValue(int value) {
    *(int*)((char*)target + 0x10094) = value;
}
