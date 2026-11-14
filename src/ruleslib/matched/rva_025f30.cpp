class MyClass {
public:
    int memberFunc(void *arg);
};

int MyClass::memberFunc(void *arg) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(arg)+0xfc);
}

