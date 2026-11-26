struct Element {
    int field_00;
    unsigned char data[88];
};

struct Container {
    int count;        // +0x00
    Element* items;   // +0x04

    Element* GetElementAt(unsigned char index);
};

Element* Container::GetElementAt(unsigned char index) {
    if (items != 0 && index < count) {
        return &items[index];
    }
    return 0;
}
