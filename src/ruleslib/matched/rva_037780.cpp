struct Record
{
    char unknown[0x5c];
    unsigned short value;
};

unsigned short __stdcall SubtractFromField(Record* record, unsigned short amount)
{
    record->value -= amount;
    return record->value;
}
