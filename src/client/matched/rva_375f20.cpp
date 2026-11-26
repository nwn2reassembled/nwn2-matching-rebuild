struct CmdBlock {
    unsigned char bytes[9 * 0x10c];
    void SetSlotByte(unsigned char index, unsigned char value);
};

void CmdBlock::SetSlotByte(unsigned char index, unsigned char value) {
    if (index < 4) {
        bytes[(index + 5) * 0x10c] = value;
    }
}
