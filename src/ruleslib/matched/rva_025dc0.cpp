struct MyStruct {
    static int __stdcall getValue(int* ptr, int idx);
};

int __stdcall MyStruct::getValue(int* ptr, int idx) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0xA8 + idx * sizeof(int));
}
