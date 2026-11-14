struct MyStruct {
    char field0;
    char field1;
    char field2;
    char field3;
    char field4;
    char field5;
    int field8;
    MyStruct* init();
};

MyStruct* MyStruct::init() {
    field8 = 0;
    field0 = 0;
    field1 = 0;
    field2 = 0;
    field3 = 0;
    field4 = 0;
    field5 = static_cast<char>(-1);
    return this;
}
