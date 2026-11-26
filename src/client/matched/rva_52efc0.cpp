void __cdecl SetFieldCB(void* obj, unsigned int value)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(obj) + 0xCB) = value;
}
