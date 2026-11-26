typedef unsigned short WORD;

class TableLookup {
public:
    WORD GetEntry(unsigned char index);

    char pad[0xBC];
    WORD* entries;            // +0xBC
    unsigned char entryCount; // +0xC0
};

WORD TableLookup::GetEntry(unsigned char index)
{
    if (index >= entryCount)
        return 0xFFFF;
    return entries[index];
}
