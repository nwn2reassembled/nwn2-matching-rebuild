struct Record {
    char pad[0x40];
    unsigned int active;
    char tail[8];
};

struct Legacy {
    char pad1[0x164];
    unsigned char count;
    char pad2[0x33];
    Record* volatile arrayBase;
    Record* getItem(unsigned short idx);
};

Record* Legacy::getItem(unsigned short idx) {
    if (idx < count) {
        Record* base = arrayBase;
        Record* item = base + idx;
        if (item->active)
            return item;
    }
    return 0;
}
