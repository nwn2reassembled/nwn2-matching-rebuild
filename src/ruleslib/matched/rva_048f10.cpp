struct Legacy {
    const unsigned char* data;
    unsigned int length;
    int find_last(unsigned char);
};

int Legacy::find_last(unsigned char ch) {
    // Search backwards for the last occurrence of ch.
    for (int i = static_cast<int>(length)-1; i >= 0; --i) {
        if (data[i] == ch)
            return i;
    }
    return -1;
}

