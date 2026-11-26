struct MyClass {
    unsigned char* data;          // Pointer to a structure that contains the 16‑bit value at offset 0x139C
    bool compare(unsigned int arg); // Returns true if low 16 bits of arg equal that stored value
};

bool MyClass::compare(unsigned int arg) {
    unsigned short stored = *reinterpret_cast<unsigned short*>(data + 0x139C);
    return static_cast<unsigned short>(arg) == stored;
}
