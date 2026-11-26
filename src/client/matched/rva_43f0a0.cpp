struct SmallString
{
    char prefix[16];
    union Storage
    {
        char* pointer;
        char buffer[16];
    } storage;
    char gap[4];
    unsigned int capacity;

    char* data();
};

char* SmallString::data()
{
    if (capacity >= 16)
        return storage.pointer;
    return storage.buffer;
}
