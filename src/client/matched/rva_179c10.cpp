struct MyStruct {
    char padding[64];
    int* array;
    void setValue(int idx, int val);
};

void MyStruct::setValue(int idx, int val) {
    array[idx] = val;
}

