struct MyStruct {
    char pad[356];
    int value;
    void setZero();
};

void MyStruct::setZero() { value = 0; }
