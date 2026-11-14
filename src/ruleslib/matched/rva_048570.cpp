class MyClass {
public:
    int foo(int);
private:
    char _pad[52];            // Padding to reach offset 0x34
    void* field;              // Pointer stored at offset 0x34
};

int MyClass::foo(int index) {
    int *base = reinterpret_cast<int*>(field);   // Load the pointer from the member.
    return *(base + 2 + 4 * index);             // Return the dword at [field+8+16*index].
}

