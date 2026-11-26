struct Record
{
    char reserved[16];
    unsigned short field;
};

void __stdcall StoreRecordField(Record* record, unsigned short value)
{
    record->field = value;
}
