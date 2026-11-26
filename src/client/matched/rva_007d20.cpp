struct Entry {
    /* fields unknown; stride is 8 bytes, flag lives at offset 0xa8 */
    unsigned char m_flags[0xb0];
};

int MarkEntry(Entry* table, unsigned int index, unsigned char* pOut)
{
    *pOut = 1;
    table->m_flags[index * 8 + 0xa8] = 1;
    return 0;
}
