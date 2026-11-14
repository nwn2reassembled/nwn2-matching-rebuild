struct MyStruct {
    int field0;
    int field4;
    int method(int);
};

int MyStruct::method(int arg) {
    if (field4 != 0 && arg >= 0 && arg < field0)
        return 1;
    return 0;
}
