struct Header {
    int** entries;
    int count;
};

struct Class {
    char pad0[0x1c];
    Header* listHeader;
    int* GetEntry(int index);
};

int* Class::GetEntry(int index) {
    if (index >= 0) {
        Header* header = this->listHeader;
        if (index < header->count) {
            int** table = header->entries;
            return table[index];
        }
    }
    return 0;
}
