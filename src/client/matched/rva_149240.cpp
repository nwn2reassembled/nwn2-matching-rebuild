struct MyStruct {
    unsigned int dummy;
    unsigned int value;
    unsigned int getValueAdjusted() const;
};

unsigned int MyStruct::getValueAdjusted() const
{
    return value + 0x1015cU;
}

