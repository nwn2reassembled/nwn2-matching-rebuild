struct MyStruct {
    int dummy1;
    int dummy2;
    unsigned int value;

    void set_value(unsigned int val);
};

void MyStruct::set_value(unsigned int val) {
    value = val;
}

