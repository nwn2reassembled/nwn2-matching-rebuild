struct Buffer
{
    unsigned int values[0x60];
    unsigned int flag;

    Buffer* Clear();
};

Buffer* Buffer::Clear()
{
    flag = 0;
    for (unsigned int i = 0; i < 0x60; ++i)
        values[i] = 0;
    return this;
}
