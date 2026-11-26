struct Context
{
    unsigned char active;
    unsigned int primaryValue;
    unsigned char pad[0x43];
    unsigned int fallbackValue;
};

unsigned int __fastcall Context_GetValue(const Context* pCtx)
{
    if (pCtx->active)
        return pCtx->primaryValue;
    return pCtx->fallbackValue;
}
