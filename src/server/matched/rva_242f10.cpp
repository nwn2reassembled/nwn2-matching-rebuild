struct ServerObj
{
    int m_count;   // +0x2368 in full object
    int m_limit;   // +0x236c in full object
};

void __fastcall ServerObj_SetAccum(ServerObj* obj, int /*unused*/, int base, int flag)
{
    if (flag != 0)
    {
        *(int*)((char*)obj + 0x2368) = 0;
        *(int*)((char*)obj + 0x236c) = flag;
        return;
    }
    int count = *(int*)((char*)obj + 0x2368);
    if (count > 0)
        *(int*)((char*)obj + 0x2368) = count + base;
    else
        *(int*)((char*)obj + 0x2368) = base;
}
