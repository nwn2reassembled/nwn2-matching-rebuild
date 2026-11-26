struct Container {
    unsigned char padding[0x2a4];
    void** entries;
    int reserved;
    int count;

    void* at(int index) const;
};

void* Container::at(int index) const {
    if (index < 0 || index >= count)
        return 0;
    return entries[index];
}
