struct Rec {
    unsigned char* table;

    unsigned char* GetEntry(unsigned int idx);
};

unsigned char* Rec::GetEntry(unsigned int idx)
{
    return idx < 0x60 ? table + idx * 120 + 0x37690 : 0;
}
