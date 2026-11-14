struct MyStruct {
    unsigned short* array;
    int count;
    void removeWord(const void* key);
};

void MyStruct::removeWord(const void* key) {
    int i = 0;
    if (count > 0) {
        const unsigned short* src = static_cast<const unsigned short*>(key);
        unsigned short target = *src;
        while (i < count && array[i] != target) ++i;
    }
    if (i >= count) return;
    --count;
    if (i < count) {
        for (; i < count; ++i)
            array[i] = array[i + 1];
    }
}
