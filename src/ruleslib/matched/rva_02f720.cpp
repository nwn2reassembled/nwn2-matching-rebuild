struct DatabaseRow {
    unsigned char  raw[0x898];
};

int GetDatabaseRowSize()
{
    return sizeof(DatabaseRow);
}
