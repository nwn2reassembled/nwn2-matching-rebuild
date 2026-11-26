struct Entry {
    int pad0[198];   // 0x000..0x317
    int id;          // 0x318
    int pad1[4];     // 0x31C..0x32B
    int type;        // 0x32C
    int pad2[2];     // 0x330..0x337
};

class Container {
public:
    int    count;    // 0x00
    Entry* entries;  // 0x04

    Entry* Find(int id);
};

Entry* Container::Find(int id)
{
    int count = this->count;
    for (int i = 0; i < count; i++)
    {
        if (this->entries[i].id == id && this->entries != 0 && i >= 0 && i < count
            && this->entries[i].type == 1)
        {
            return &this->entries[i];
        }
    }
    return 0;
}
