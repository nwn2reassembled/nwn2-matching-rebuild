struct SomeRecord {
    unsigned char pad[0x40];
    unsigned int active;
    unsigned char tail[0x8];
};

struct SomeObject {
    unsigned char pad0[0x164];
    unsigned char entryCount;
    unsigned char pad1[0x33];
    SomeRecord* entries;
};

int __stdcall HasActiveEntry(SomeObject* obj, unsigned short index)
{
    if (index < (unsigned short)obj->entryCount && obj->entries[index].active != 0)
        return 1;
    return 0;
}
