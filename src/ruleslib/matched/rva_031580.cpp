struct RulesObject
{
    unsigned char reserved[0x5f6];
    unsigned char value;
};

unsigned char __stdcall ReadRulesObjectByte(const RulesObject* object)
{
    return object->value;
}
