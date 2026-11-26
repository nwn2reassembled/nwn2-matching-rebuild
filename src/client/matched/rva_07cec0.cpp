int __fastcall GetSomeValue(void* obj)
{
    if (*(char*)obj != 0)
        return *(int*)((char*)obj + 0x3c);
    return *(int*)((char*)obj + 0x74);
}
