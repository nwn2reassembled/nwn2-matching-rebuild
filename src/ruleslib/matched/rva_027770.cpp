struct MyStruct {
    void setFlag(int* p);
};

void MyStruct::setFlag(int* p) {
    *(int*)((char*)p + 0x330) = 1;
}

