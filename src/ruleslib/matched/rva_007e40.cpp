struct MyStruct {
    short field0;
    int field4;
    char field8;
    MyStruct* init();
};

MyStruct* MyStruct::init() {
    field0 = -1;
    field4 = 1;
    field8 = 0;
    return this;
}
