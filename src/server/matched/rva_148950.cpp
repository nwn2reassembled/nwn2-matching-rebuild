struct PacketHeader {
    unsigned int field00;
    unsigned int field04;
    unsigned int field08; // offset 0x08
    unsigned int field0C; // offset 0x0C
    unsigned int field10; // offset 0x10
    unsigned int field14; // offset 0x14
    unsigned int field18; // offset 0x18
    unsigned int field1C; // offset 0x1C
};

void ClearPacketHeader(PacketHeader* header)
{
    header->field18 = 0;
    header->field14 = 0;
    header->field1C = 0;
    header->field0C = 0;
    header->field08 = 0;
    header->field10 = 0;
}
