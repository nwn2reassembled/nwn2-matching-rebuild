struct IntList {
    int* data;
    int count;
    void erase(const int& value);
};

void IntList::erase(const int& value) {
    int i = 0;
    while (i < count && data[i] != value)
        ++i;
    if (i < count) {
        --count;
        for (; i < count; ++i)
            data[i] = data[i + 1];
    }
}
