struct MyStruct {
    unsigned int flags;
    float values[5];
    void setAll(float val);
};

void MyStruct::setAll(float val) {
    flags = 0;
    for (int i = 0; i < 5; ++i)
        values[i] = val;
}

