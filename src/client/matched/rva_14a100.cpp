struct MyStruct {
    int padding[14];
    int field38;
    int field3C;

    void copy(int* dst1, int* dst2);
};

void MyStruct::copy(int* dst1, int* dst2) {
    *dst1 = this->field38;
    *dst2 = this->field3C;
}

