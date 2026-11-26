struct Block32
{
    unsigned int values[8];
};

Block32 * __stdcall CopyBlock32(Block32 *dst)
{
    *dst = *reinterpret_cast<const Block32 *>(0x86cce8);
    return dst;
}
