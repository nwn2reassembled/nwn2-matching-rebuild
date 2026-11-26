struct Item { int values[6]; };

struct Container
{
    unsigned char padding[0x470];
    Item items[1];
};

Item* __stdcall GetItem(Container* container, unsigned char index)
{
    return &container->items[index];
}
