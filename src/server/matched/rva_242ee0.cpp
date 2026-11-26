class ServerInfo
{
public:
    unsigned int reserved[2264];
    unsigned int field_2360;
    unsigned int field_2364;
    unsigned int reserved2;
    unsigned int field_236C;

    void __thiscall Update(unsigned int a, unsigned int b);
};

void __thiscall ServerInfo::Update(unsigned int a, unsigned int b)
{
    this->field_2360 = a;
    this->field_2364 = b;
    if (this->field_236C != 0 && a == 0)
        this->field_236C = a;
}
