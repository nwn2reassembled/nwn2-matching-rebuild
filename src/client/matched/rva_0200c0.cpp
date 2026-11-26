struct Object
{
    unsigned char unknown[0x340];
    int first;
    int second;
};

void SetPair(Object* object, int first, int second)
{
    object->first = first;
    object->second = second;
}
