struct SomeMgr {
    unsigned int pad_[16];
    unsigned int counts_[7];
    unsigned int status_;
};

int __cdecl SomeMgr_CheckEntry(SomeMgr* mgr, unsigned int index)
{
    if (mgr == 0)
        return 0;
    if (mgr->counts_[index] == 0)
        return 0;
    unsigned int v = (&mgr->counts_[index])[7];
    return (v & 0x60) != 0;
}
