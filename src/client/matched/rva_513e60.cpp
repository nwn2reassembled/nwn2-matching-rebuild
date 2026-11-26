// Accessor into a packed record whose dword member sits at byte offset 0xCF
// (the surrounding layout is not 4-byte aligned, so the offset is expressed
// directly rather than through a default-aligned struct member).

int ExchangeValue(char* record, int newValue)
{
    int oldValue = *(int*)(record + 0xCF);
    *(int*)(record + 0xCF) = newValue;
    return oldValue;
}
