struct Item {
    unsigned char bytes[64];
};

struct Container {
    unsigned char padding0[0x15c];
    unsigned char itemCount;
    unsigned char padding1[0x17];
    Item* items;

    Item* Get(unsigned short index);
};

Item* Container::Get(unsigned short index) {
    if (index < itemCount) {
        return items + index;
    }
    return 0;
}
