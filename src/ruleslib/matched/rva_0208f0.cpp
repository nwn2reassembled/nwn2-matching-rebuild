struct Record {
    char pad[0x318];
    int key;
    char gap[0x10];
    int active;
    char tail[8];
};

struct MyStruct {
    int count;
    Record* array;
    Record* find(int key);
};

Record* MyStruct::find(int key) {
    int n = count;
    int i = 0;
    if (n > 0) {
        Record* base = array;
        Record* ptr = base;
        do {
            if (ptr->key == key && base && i >= 0 && i < n && ptr->active == 1)
                return base + i;
            ++i;
            ++ptr;
        } while (i < n);
    }
    return 0;
}
