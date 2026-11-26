// The accessed field sits at byte offset 0xD7, which is not 4-byte aligned,
// so the object is treated as a raw byte buffer (e.g. a serialized record or
// network message) and the dword is read and written at that fixed offset.

int Buffer_GetSetDword(unsigned char* obj, int value)
{
    int oldValue = *(int*)(obj + 0xD7);
    *(int*)(obj + 0xD7) = value;
    return oldValue;
}
