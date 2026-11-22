class MyClass {
public:
    int get() const;
private:
    int dummy_;
    void* ptr_;
};

int MyClass::get() const {
    return *reinterpret_cast<const int*>(static_cast<const char*>(ptr_) + 0x100c4);
}

