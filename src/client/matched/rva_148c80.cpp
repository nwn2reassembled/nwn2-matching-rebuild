class MyClass {
public:
    int getValue();
private:
    int placeholder; // occupies offset 0-3
    void* ptr;        // occupies offset 4
};

int MyClass::getValue() {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x10068);
}

