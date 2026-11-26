struct FixedBlock {
    unsigned char data[0x368];
};

FixedBlock* GetFixedBlock()
{
    return reinterpret_cast<FixedBlock*>(0x368);
}
