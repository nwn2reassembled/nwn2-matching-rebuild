struct MyStruct {
    int a;
    int b;
    int c;
    int d;
    int foo();
};

int MyStruct::foo() {
    return d + 4;
}

