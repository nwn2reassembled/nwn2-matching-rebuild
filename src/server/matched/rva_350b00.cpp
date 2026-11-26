struct Buffer
{
    int count;
    const void* data;

    int ContainsIndex(int index);
};

int Buffer::ContainsIndex(int index)
{
    if (data != 0 && index >= 0 && index < count)
        return 1;

    return 0;
}
