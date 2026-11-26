struct Blob56
{
    int data[14];
};

void __stdcall CopyBlob(Blob56* dest, const Blob56* src)
{
    if (dest != 0)
        *dest = *src;
}
