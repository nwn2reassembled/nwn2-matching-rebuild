void __stdcall CNWRules_SetByteFieldAtOffset5(void* pObject, unsigned char value)
{
    if (pObject != 0)
    {
        *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(pObject) + 5) = value;
    }
}
