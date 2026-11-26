struct CNWRealm
{
    unsigned char pad0[0x14];
    unsigned char* field14;
};

void __stdcall CNWRealm_SetField14(CNWRealm* pRealm, unsigned char* value)
{
    if (pRealm != 0)
    {
        pRealm->field14 = value;
    }
}
