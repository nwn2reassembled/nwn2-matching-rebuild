struct RuleRecord
{
    int fields[8];
};

struct RulesBlock
{
    unsigned char prefix[404];
    RuleRecord records[1];
};

RuleRecord* __stdcall GetRuleRecord(RulesBlock* block, int index)
{
    return &block->records[index];
}
