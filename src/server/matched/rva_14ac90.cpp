class Legacy {
public:
    unsigned int getValue();
};

unsigned int Legacy::getValue() {
    // Load the pointer stored at absolute address 0x86442c
    unsigned int* basePtr = reinterpret_cast<unsigned int*>(0x86442c);
    unsigned int base = *basePtr;
    // Return the dword located 32 bytes after that pointer
    return *(reinterpret_cast<unsigned int*>(base + 0x20));
}

