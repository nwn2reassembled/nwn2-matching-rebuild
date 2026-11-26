typedef unsigned short uint16;

struct Target {
    char padding[0x70];
    uint16 value;
};

void __stdcall SetTargetValue(Target* target, uint16 value)
{
    target->value = value;
}
