struct RulesDB
{
    unsigned char pad[0x40];
    unsigned long flags;

    unsigned long GetFlags();
};

unsigned long RulesDB::GetFlags()
{
    return this->flags;
}
