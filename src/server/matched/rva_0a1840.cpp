struct Table
{
    int mode;
    int base;
    int stride;

    int at(int index);
};

int Table::at(int index)
{
    if (mode == 0)
        return stride * index + base;

    return reinterpret_cast<int*>(base)[index];
}
