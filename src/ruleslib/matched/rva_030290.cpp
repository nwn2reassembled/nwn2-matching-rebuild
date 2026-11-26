struct Record
{
    char padding[0x6a];
    unsigned short value;
};

void __stdcall update(Record* object, unsigned short value)
{
    object->value = value;
}
