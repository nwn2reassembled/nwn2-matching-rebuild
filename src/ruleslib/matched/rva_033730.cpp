struct Object48
{
    char padding[0x48];
    unsigned char value;
};

unsigned char __stdcall GetObject48Value(Object48* object)
{
    return object->value;
}
