struct Target
{
    unsigned char reserved[0x44];
    unsigned char value;
};

void __stdcall SetTargetValue(Target* target, unsigned char value)
{
    target->value = value;
}
