struct ServerInfo
{
    unsigned int field_0;
    unsigned int field_4;
    unsigned char field_8;   // 0x9 - 0xB padding
    unsigned int field_c;
    unsigned int field_10;
    unsigned char field_14;  // 0x15 - 0x17 padding
    unsigned int field_18;

    void CopyFrom(ServerInfo* src);
};

void ServerInfo::CopyFrom(ServerInfo* src)
{
    if (src != 0)
    {
        this->field_4  = src->field_4;
        this->field_0  = src->field_0;
        this->field_8  = src->field_8;
        this->field_c  = src->field_c;
        this->field_10 = src->field_10;
        this->field_14 = src->field_14;
        this->field_18 = src->field_18;
    }
}
