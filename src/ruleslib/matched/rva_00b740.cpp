class Legacy {
public:
    char pad[40];
    unsigned short* array_ptr;
    int value;
    short get(unsigned short idx);
};

short Legacy::get(unsigned short idx) {
    if (idx >= value)
        return -1;
    return array_ptr[idx];
}
