struct RulesInfo
{
    unsigned long version;

    unsigned long __cdecl GetVersion() const;
};

unsigned long __cdecl RulesInfo::GetVersion() const
{
    return 0x487;
}
