struct MyClass {
    void setValue(void* base, int val);
};

void MyClass::setValue(void* base, int val) {
    *reinterpret_cast<int*>(static_cast<char*>(base)+0x5dc) = val;
}

