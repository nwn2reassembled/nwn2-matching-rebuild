struct Legacy {
    unsigned char pad[56];
    unsigned short count;
    unsigned short* array;
    int find(unsigned short key);
};

int Legacy::find(unsigned short key) {
    if (!array)
        return 0;
    for (unsigned short i = 0; i < count; ++i) {
        if (array[i] == key)
            return 1;
    }
    return 0;
}
