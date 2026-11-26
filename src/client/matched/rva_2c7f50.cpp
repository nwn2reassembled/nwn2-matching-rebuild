struct Sample {
    unsigned short value;
    char gap[6];
    int flag;
    unsigned short get() const;
};

unsigned short Sample::get() const
{
    unsigned short result = 0xffff;
    if (flag)
        result = value;
    return result;
}
