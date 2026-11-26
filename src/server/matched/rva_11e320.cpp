class MyClass {
public:
    // Member function using default thiscall convention
    int getValue(int idx) const;
private:
    char pad[0x34];          // Ensure field_34 starts at offset 0x34
    void* field_34;          // Pointer stored at [ecx+0x34]
};

int MyClass::getValue(int idx) const {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(field_34)
                                   + (idx << 4) + 8);
}

