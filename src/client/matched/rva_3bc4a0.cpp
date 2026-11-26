struct Item {
    unsigned char value;
    unsigned char padding[0x19b];
};

struct Container {
    unsigned char header[0x1c];
    Item items[3];
    unsigned char reserved[0x7c];
    int dirty;
    unsigned char* SetValue(unsigned char value, int index);
};

unsigned char* Container::SetValue(unsigned char value, int index)
{
    unsigned char* slot = &items[index].value;
    if (value != *slot) {
        dirty = 1;
    }
    *slot = value;
    return slot;
}
