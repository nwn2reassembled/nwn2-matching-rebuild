struct CProbe
{
    void** m_vtbl;
    void* GetSlot();
};

void* CProbe::GetSlot()
{
    void** vtbl = *(void***)this;
    if (vtbl == 0)
        return 0;
    return vtbl[2];
}
