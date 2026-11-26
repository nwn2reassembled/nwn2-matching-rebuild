struct ObjectWithFlags
{
    unsigned char padding[0x6d0];
    unsigned char flags;
};

int __stdcall GetFlagBit3(const ObjectWithFlags* object)
{
    return (object->flags >> 3) & 1;
}
