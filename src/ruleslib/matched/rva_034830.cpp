struct RulesEngineData {
    unsigned char bytes[0x88];
};

unsigned int __stdcall GetRulesEngineDataSize()
{
    return sizeof(RulesEngineData);
}
