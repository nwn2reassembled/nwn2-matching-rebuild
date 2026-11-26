struct RuleEntry {
    unsigned char pad[4];
    unsigned char active;
};

void __stdcall RuleEntry_SetActive(RuleEntry* entry, unsigned char value)
{
    if (entry != 0) {
        entry->active = value;
    }
}
