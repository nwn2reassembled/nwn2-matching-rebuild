struct Item { char bytes[40]; };

class List {
public:
    unsigned long count;
    Item* items;

    Item* __thiscall GetItem(int index);
};

Item* List::GetItem(int index) {
    if (items == 0)
        return 0;
    if (index < 0 || index >= (int)count)
        return 0;
    return &items[index];
}
