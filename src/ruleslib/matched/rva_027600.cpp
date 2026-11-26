struct Record {
    int reserved0;
    int reserved1;
    int reserved2;
    int reserved3;
    int value;
};

int __stdcall StoreValue(Record* record, int value)
{
    record->value = value;
    return value;
}
