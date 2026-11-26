struct MyClass {
    int member;
    int get(int* ptr);
};

int MyClass::get(int* ptr) { return *ptr; }
