class MyClass {
public:
    void set(void*);
private:
    int dummy;
    void* field;
};

void MyClass::set(void* p) {
    *reinterpret_cast<void**>((static_cast<char*>(field)+0x100b8)) = p;
}

