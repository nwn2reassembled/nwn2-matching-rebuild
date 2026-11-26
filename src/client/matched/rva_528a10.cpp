struct Object
{
    char padding[0x149];
    unsigned char flags;
};

int ReadIfFlagged(Object* object, short value)
{
    if ((object->flags & 5) != 0)
        return value;

    return 0;
}
