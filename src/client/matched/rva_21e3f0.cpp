struct Obj {
    unsigned char b0;
    unsigned char b1;
    unsigned char flag;
};

class CThing {
public:
    void ClearFlags();

    void* m_slots[42];   // offsets 0x00..0xA7
    Obj** m_items;       // offset 0xA8
    int m_count;         // offset 0xAC
};

void CThing::ClearFlags() {
    for (unsigned short i = 0; i < m_count; ++i) {
        Obj* item = m_items[i];
        if (item != 0) {
            item->flag = 0;
        }
    }
}
