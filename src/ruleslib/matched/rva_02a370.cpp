struct Blob
{
    char data[828];
};

unsigned int __stdcall GetBlobSize();

unsigned int __stdcall GetBlobSize()
{
    return sizeof(Blob);
}
