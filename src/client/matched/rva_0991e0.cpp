struct BigStruct {
    int fields[92];
};

void __stdcall CopyBigStruct(BigStruct* dest, const BigStruct* src)
{
    if (dest != 0)
        *dest = *src;
}
