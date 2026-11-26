struct Target {
    char padding[0x70];
    int value;
};

void __stdcall SetTargetValue(Target* target, int value)
{
    target->value = value;
}
