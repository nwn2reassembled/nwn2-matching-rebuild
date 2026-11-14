struct MyClass {
    // Padding to reach offset 0x44 where the data pointer resides
    char pad[0x44];
    unsigned int* data;          // Pointer stored at [this+0x44]
    unsigned int getValue(unsigned int index) const;
};

unsigned int MyClass::getValue(unsigned int index) const {
    // Compute address: base = data + index * 8 + 4 bytes
    return *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(data) + (index << 3) + 4);
}

