struct RulesTable
{
    unsigned char m_bytes[0x12];
    unsigned short m_entries[6];
};

void __stdcall RulesTable_SetEntry(RulesTable *table, unsigned char index, unsigned short value)
{
    if (index < 6)
        table->m_entries[index] = value;
}
