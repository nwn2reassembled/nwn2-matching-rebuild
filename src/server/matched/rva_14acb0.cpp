struct Legacy {
    int getValue() const;
};

int Legacy::getValue() const {
    // Load the pointer stored at the absolute data address 0x86442c.
    int* base = *(int**)0x86442c;          // equivalent to mov eax, ds:0x86442c ; mov eax, [eax]
    // Return the dword located 0x20 (32) bytes after that pointer.
    return *(base + 8);                    // equivalent to add eax, 0x20 ; mov eax, [eax]
}

