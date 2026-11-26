struct RulesObject
{
    unsigned char reserved[0x308];
    unsigned char flag;
};

unsigned char __stdcall GetFlag(const RulesObject* obj)
{
    return obj->flag;
}
