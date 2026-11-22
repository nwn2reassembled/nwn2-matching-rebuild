struct Outer {
    char dummy;
    void* ptr;
    void setValue(int);
};

void Outer::setValue(int val) {
    *(int*)((char*)ptr + 0x100f0) = val;
}

