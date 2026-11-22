class MyClass {
public:
    int func();
private:
    int dummy;
    void* ptr;
};

int MyClass::func() {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x348);
}

