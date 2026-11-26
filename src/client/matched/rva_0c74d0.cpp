struct CData {
    unsigned char pad[0x8E];
    unsigned char field8E;
};

struct CThing {
    CData* data;
    unsigned char GetSubtype();
};

unsigned char __thiscall CThing::GetSubtype()
{
    CData* d = data;
    if (d != 0)
        return d->field8E;
    return 8;
}
