struct Clearable {
    void* unknown0;
    void* field04;
    void* field08;
    void* field0c;
    char pad10_to_4b[0x3c];
    void* field4c;
    void* field50;
    void* field54;

    Clearable* Reset();
};

Clearable* Clearable::Reset()
{
    field04 = 0;
    field08 = 0;
    field0c = 0;
    field4c = 0;
    field50 = 0;
    field54 = 0;
    return this;
}
