struct NetPeer {
    char  pad[0x0AA4];
    unsigned char slot[3];

    void __thiscall SetSlot(unsigned char idx, unsigned char value);
};

void NetPeer::SetSlot(unsigned char idx, unsigned char value)
{
    if (idx < 3)
        slot[idx] = value;
}
