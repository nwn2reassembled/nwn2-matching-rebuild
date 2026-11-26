struct SomeContext
{
    unsigned char gap0[0x1CF8];
    void* field_1CF8;
};

int __cdecl CheckState(const SomeContext* ctx)
{
    if (ctx->field_1CF8 == 0)
    {
        return 0;
    }
    int result;
    if (ctx->field_1CF8 == (void*)5)
        result = 0;
    else
        result = 1;
    return result;
}
