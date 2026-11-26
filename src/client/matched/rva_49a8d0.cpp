struct Holder
{
    unsigned short flag;
    unsigned int count;
    unsigned char state;

    Holder* Reset();
};

Holder* Holder::Reset()
{
    flag = 0xffff;
    count = 1;
    state = 0;
    return this;
}
