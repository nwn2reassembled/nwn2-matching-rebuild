struct Legacy {
    unsigned char data[0x335];
    unsigned char flag;
    void __stdcall SetFlag(unsigned int value);
};

void Legacy::SetFlag(unsigned int value)
{
    this->flag = (unsigned char)(value != 0);
}

