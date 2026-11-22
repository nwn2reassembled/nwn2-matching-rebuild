struct MyStruct {
    char pad[44];
    unsigned int field;
    void setZero();
};

void MyStruct::setZero() { field = 0; }
