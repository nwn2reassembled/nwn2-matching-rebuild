struct CharTable {
    unsigned char pad[8];
    /* +0x8:  */ unsigned short* data;
    /* +0xC:  */ unsigned int count;
};

class Rules {
    unsigned char pad[0x138];
    /* 0x138: */ CharTable* table;
public:
    int __stdcall GetChar(int index);
};

int Rules::GetChar(int index) {
    CharTable* rec = this->table;
    if (index < 0 || index >= static_cast<int>(rec->count))
        return 0xffff;
    return rec->data[index];
}
