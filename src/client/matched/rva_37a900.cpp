struct Entry { char data[0x10C]; };

class Container {
public:
    Entry* __fastcall GetEntry(int unused, unsigned char index);

private:
    unsigned char pad0[0x14];
    unsigned char entryCount;
    unsigned char pad1[0x41F];
};

Entry* __fastcall Container::GetEntry(int, unsigned char index)
{
    if (index < entryCount)
        return reinterpret_cast<Entry*>(reinterpret_cast<char*>(this) + 0x534 + index * 0x10C);
    return 0;
}
