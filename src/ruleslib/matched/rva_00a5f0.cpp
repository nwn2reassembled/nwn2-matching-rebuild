struct Entry {
    char pad[0x44];
    int flag;
};

struct Legacy {
    char pad[0x284];
    int count;
    Entry* array;
    void* getElement(int index);
};

void* Legacy::getElement(int index) {
    if (index >= 0 && index < count) {
        Entry* entry = array + index;
        if (entry->flag != 0)
            return entry;
    }
    return 0;
}
