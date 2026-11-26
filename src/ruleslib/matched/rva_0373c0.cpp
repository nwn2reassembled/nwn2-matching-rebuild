struct Target
{
    char padding[64];
    unsigned char value;
};

void __stdcall SetTargetValue(Target* target, unsigned char value)
{
    target->value = value;
}
