struct Record
{
    unsigned char reserved[0x44];
    unsigned short value;
};

unsigned short __stdcall ReadValue(Record* record)
{
    return record->value;
}
