struct Item {
    int a;
    int b;
    int c;
    int d;
    int value;
};

class Manager {
public:
    void SetItemValue(int value);

private:
    char reserved0[0x52c];
    Item* items;
    char reserved1[0x538 - 0x52c - sizeof(Item*)];
    int current;
};

void Manager::SetItemValue(int value) {
    int i = current;
    if (i >= 0) {
        items[i].value = value;
    }
}
