class CGameManager
{
public:
    // Scans a 39-entry pool of dwords at this+0x1D8; returns the flag byte at
    // [entry+0xA0] of the first non-zero entry, or 0 if all are empty.
    unsigned char __fastcall GetFirstEntryFlag();

    unsigned long m_pad[118];      // 0x000 .. 0x1D4
    unsigned long m_entries[39];   // 0x1D8 .. 0x274
};

unsigned char __fastcall CGameManager::GetFirstEntryFlag()
{
    int i = 0;
    unsigned long* p = &m_entries[0];

    while (i < 39)
    {
        if (*p != 0)
        {
            return *(unsigned char*)(m_entries[i] + 0xA0);
        }
        ++i;
        ++p;
    }
    return 0;
}
