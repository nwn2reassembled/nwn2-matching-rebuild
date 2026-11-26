struct RulesBlock
{
    unsigned char reserved[0x154];
    unsigned int value;
};

unsigned int __stdcall GetRulesValue(const RulesBlock* block)
{
    return block->value;
}
