struct Record
{
    int value;
    int reserved0;
    int reserved1;
    int enabled;
    int code;
};

int GetValue(Record* p)
{
    if (p == 0)
        return 0;
    if (p->enabled == 0)
        return 0;
    if (p->code != 100)
        return 0;
    return p->value;
}
