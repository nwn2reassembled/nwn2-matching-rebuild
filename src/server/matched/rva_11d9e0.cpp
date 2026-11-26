class ServerObject {
public:
    unsigned char pad[0x2c];
    int flag; // offset 0x2c

    int ClearFlag();
};

int ServerObject::ClearFlag()
{
    int result = 1;
    if (this->flag != 0)
    {
        this->flag = 0;
    }
    return result;
}
