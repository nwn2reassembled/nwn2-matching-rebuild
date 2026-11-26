struct Lookup {
    int* items;
    unsigned char count;
    int Get(unsigned char index) const;
};

int Lookup::Get(unsigned char index) const {
    int result = 0;
    if (index > 0 && index < count && items != 0)
        result = items[index];
    return result;
}
