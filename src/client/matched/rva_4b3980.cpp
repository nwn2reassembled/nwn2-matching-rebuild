struct MyStruct {
    int foo(int);
};

int MyStruct::foo(int arg) {
    return reinterpret_cast<int>(this) + 12 * arg;
}

