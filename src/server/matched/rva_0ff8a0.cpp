struct BigStruct {
    unsigned char pad0[0x14];
    int field14;
    unsigned char pad18[0x4];
    int field1c;
    unsigned char pad20[0x91c];
};

struct Entry {
    unsigned char pad0[0x10];
    int inUse;
    unsigned char pad14[0xc];
    int linkedIndex;
    unsigned char pad24[0x54];
};

class Server {
public:
    BigStruct m_big[96];
    Entry m_entries[896];

    int GetLinkedValue(int entryIndex, int* outValue);
};

int Server::GetLinkedValue(int entryIndex, int* outValue)
{
    if (m_entries[entryIndex].inUse != 0)
    {
        int linkedIndex = m_entries[entryIndex].linkedIndex;
        if (m_big[linkedIndex].field14 != 0)
        {
            *outValue = m_big[linkedIndex].field1c;
            return 1;
        }
    }
    return 0;
}
