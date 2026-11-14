struct MyContainer {
    unsigned short* data;
    unsigned int padding;
    int count;
    bool contains(const unsigned short* valuePtr) const;
};

bool MyContainer::contains(const unsigned short* valuePtr) const {
    int index = 0;
    if (count > 0) {
        unsigned short target = *valuePtr;
        const unsigned short* ptr = data;
        do {
            if (*ptr == target)
                goto found;
            ++index;
            ++ptr;
        } while (index < count);
    }
    index = -1;
found:
    return index != -1;
}
