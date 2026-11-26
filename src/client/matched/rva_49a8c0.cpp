struct InitTarget
{
    unsigned short sentinel;
    unsigned short reserved;
    unsigned int firstValue;
    unsigned int secondValue;
    unsigned int thirdValue;

    InitTarget* initialize();
};

InitTarget* InitTarget::initialize()
{
    sentinel = 0xffff;
    firstValue = 0;
    thirdValue = 0;
    return this;
}
