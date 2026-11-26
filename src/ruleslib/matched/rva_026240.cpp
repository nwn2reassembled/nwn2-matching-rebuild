struct RulesObject
{
    unsigned char unknown[0x17C];
    unsigned int value;
};

unsigned int __stdcall GetRulesObjectValue(RulesObject* object)
{
    return object->value;
}
