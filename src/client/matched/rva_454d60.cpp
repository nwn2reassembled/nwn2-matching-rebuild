struct Record
{
    unsigned int fields[14];
};

void __cdecl CopyChunkArray(Record* dst, Record* dstEnd, const Record* src)
{
    for (Record* p = dst; p != dstEnd; ++p)
    {
        *p = *src;
    }
}
