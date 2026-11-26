struct Item
{
    unsigned char bytes[0x5c];
};

class ItemArray
{
public:
    int count;
    Item* data;

    Item* At(unsigned char index);
};

Item* ItemArray::At(unsigned char index)
{
    if (data != 0 && static_cast<int>(index) < count)
        return data + index;
    return 0;
}
