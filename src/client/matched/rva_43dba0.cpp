struct MyStruct {
    int foo();
};
int MyStruct::foo() {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x70);
}
