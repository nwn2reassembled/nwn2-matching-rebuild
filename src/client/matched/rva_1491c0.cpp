struct MyStruct {
    // Virtual function to force a vtable pointer at offset 0.
    virtual ~MyStruct() {}

    // Ordinary data member located at offset 4.
    unsigned int* ptr;

    unsigned int getValue();
};

unsigned int MyStruct::getValue()
{
    // Load the DWORD located at (ptr + 0x1000c).
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr) + 0x1000c);
}

