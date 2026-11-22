struct MyStruct {
    int foo(int);
};

int MyStruct::foo(int a) { return a + 0xc2; }
