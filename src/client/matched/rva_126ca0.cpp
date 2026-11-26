class Status
{
public:
    int field_00[11]; // 0x00 .. 0x28, unnamed
    int flag;         // 0x2c

    int ClearFlag();
};

int Status::ClearFlag()
{
    if (flag != 0)
        flag = 0;
    return 1;
}
