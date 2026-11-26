struct Container
{
    char reserved[0x200];
    int* items;
    int pad;
    int count;

    int GetItem(int index);
};

int Container::GetItem(int index)
{
    if (index >= 0 && index < count)
        return items[index];
    return 0;
}
