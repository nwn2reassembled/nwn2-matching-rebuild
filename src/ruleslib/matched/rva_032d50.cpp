struct NWN2Object
{
    unsigned char m_bytes[0x10];
    unsigned short m_value16;
};

void __stdcall NWN2Object_SetWord(NWN2Object* obj, unsigned short value)
{
    if (obj != 0)
    {
        obj->m_value16 = value;
    }
}
