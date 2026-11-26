void __cdecl Adjust(unsigned int *value, const unsigned char *data, unsigned int scale)
{
    *value -= *reinterpret_cast<const unsigned int *>(data + 0x112) * scale /
              *reinterpret_cast<const unsigned int *>(data + 0x116);
}
