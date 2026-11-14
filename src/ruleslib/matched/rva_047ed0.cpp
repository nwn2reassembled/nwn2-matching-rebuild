struct Legacy {
    char pad[0x38];
    void* field_38;
    int getValue(int idx) const;
};

int Legacy::getValue(int idx) const {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(field_38) + 0x30 + idx * 0x34);
}
