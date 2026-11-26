struct Entry {
    unsigned char pad[0x1c0];
    unsigned char field_1c0;
};

struct SomeManager {
    unsigned char pad[0x1d8];
    Entry* entries[39];

    void SetFlagOnEntries(unsigned char value);
};

void SomeManager::SetFlagOnEntries(unsigned char value)
{
    Entry** p = &entries[1];
    for (int i = 13; i != 0; --i) {
        if (p[-1]) p[-1]->field_1c0 = value;
        if (p[0])  p[0]->field_1c0 = value;
        if (p[1])  p[1]->field_1c0 = value;
        p += 3;
    }
}
