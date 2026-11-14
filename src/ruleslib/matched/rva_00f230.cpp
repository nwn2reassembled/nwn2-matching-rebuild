struct Legacy {
    char pad0[0x44];
    const unsigned short* array;
    char pad1[4];
    int count;
    int find(unsigned short value) const;
};

int Legacy::find(unsigned short value) const {
    int index = 0;
    if (count > 0) {
        const unsigned short* ptr = array;
        do {
            if (*ptr == value)
                goto found;
            ++index;
            ++ptr;
        } while (index < count);
    }
    index = -1;
found:
    return index != -1;
}
