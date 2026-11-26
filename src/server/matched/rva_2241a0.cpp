struct CItemArray {
    void** items;
    int count;
};

struct CListContainer {
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    CItemArray* itemArray;

    void* GetItem(int index);
};

void* CListContainer::GetItem(int index) {
    if (index >= 0 && index < itemArray->count) {
        return itemArray->items[index];
    }
    return 0;
}
