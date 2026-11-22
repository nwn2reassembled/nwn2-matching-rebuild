struct MyStruct {
    char pad[0x454];
    int value;
    int* getPtr();
};

int* MyStruct::getPtr() { return &value; }
