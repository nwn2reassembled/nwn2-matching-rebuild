class MyClass {
public:
    int getValue() const;
private:
    char pad[4];
    void* inner; // offset 4
};

int MyClass::getValue() const {
    return *reinterpret_cast<const int*>(reinterpret_cast<char*>(inner) + 0x10080);
}

