unsigned int __cdecl GetItemField(void* obj, unsigned int index)
{
    return *(unsigned int*)((char*)obj + 0x390 + index * 4);
}
