class MyClass {
public:
    unsigned int foo(void* arg);
};

unsigned int MyClass::foo(void* arg) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(arg)+0x1E4);
}

