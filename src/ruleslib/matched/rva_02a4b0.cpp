typedef struct { unsigned char data[0x350]; } DBConfigRecord;

unsigned int __cdecl GetDBConfigRecordSize()
{
    return sizeof(DBConfigRecord);
}
