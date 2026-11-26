int __cdecl GetSomething(void* obj)
{
    return *(int*)((char*)obj + 0x48);
}
