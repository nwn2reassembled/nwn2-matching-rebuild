struct IndexedShorts
{
    int unknown0;
    int unknown1;
    int unknown2;
    int unknown3;
    int unknown4;
    int unknown5;
    short* values;
    int length;

    short at(unsigned short index);
};

short IndexedShorts::at(unsigned short index)
{
    if (static_cast<int>(index) >= length)
        return -1;

    return values[index];
}
