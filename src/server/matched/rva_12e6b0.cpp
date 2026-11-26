int GetFirstValue(const void* table)
{
    const int* entry = (const int*)table;
    return *entry;
}
