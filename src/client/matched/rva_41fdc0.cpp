struct MyClass {
    // Pad to reach offset 0xA8
    char pad[0xa8];
    unsigned int value;          // member at offset 0xA8
    void setZero();              // declared here, defined out‑of‑line
};

void MyClass::setZero() {
    this->value = 0;             // writes a dword of zero to [ecx+0xa8]
}

