struct RowTable {
    unsigned char rows[9][0x10c];
    unsigned char GetRowByte(unsigned char index);
};

unsigned char RowTable::GetRowByte(unsigned char index) {
    if (index >= 4)
        return 0;
    return rows[index + 5][0];
}
