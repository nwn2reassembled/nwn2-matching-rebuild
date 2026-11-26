struct RulesTable {
    char reserved[0x3e];
    unsigned short entries[27];
    int __stdcall get_value(int index) const;
};

int __stdcall RulesTable::get_value(int index) const {
    if (index < 0)
        return 0xffff;
    else if (index < 0x1b)
        return entries[index];
    else
        return 0xffff;
}
