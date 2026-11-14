class MyClass {
public:
    int func(void*);
};
int MyClass::func(void* p) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x14c);
}
