class MyClass {
public:
    static int __stdcall getValue(void* ptr);
};

int MyClass::getValue(void* ptr) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x8c);
}

