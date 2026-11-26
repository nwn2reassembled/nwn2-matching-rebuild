struct RulesData
{
    unsigned char bytes[0x868];
};

unsigned int __stdcall GetRulesDataSize()
{
    return sizeof(RulesData);
}
