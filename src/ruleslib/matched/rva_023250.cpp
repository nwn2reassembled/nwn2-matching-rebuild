struct Legacy {
    int* array;
    unsigned char limit;
    int get(unsigned char idx) const;
};

int Legacy::get(unsigned char idx) const {
    int result = 0;
    if (idx > 0 && idx < limit && array)
        result = array[idx];
    return result;
}
