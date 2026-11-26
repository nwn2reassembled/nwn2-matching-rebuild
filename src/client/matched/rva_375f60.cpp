struct EffectTable {
    void __thiscall set_entry_value(unsigned char index, unsigned char value);
};

void __thiscall EffectTable::set_entry_value(unsigned char index, unsigned char value) {
    if (index < 4) {
        *(unsigned char*)((char*)this + index * 0x10c + 0x53d) = value;
    }
}
