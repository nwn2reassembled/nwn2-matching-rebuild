struct MyStruct {
    int a;
    int b;
    int c;
    MyStruct* clear();
};

MyStruct* MyStruct::clear() {
    a = 0;
    b = 0;
    c = 0;
    return this;
}
