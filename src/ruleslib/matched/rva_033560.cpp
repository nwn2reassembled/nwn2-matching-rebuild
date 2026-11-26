typedef unsigned char NWN2RulesObj;

bool __stdcall IsFlagActive(NWN2RulesObj *obj)
{
    return 0 < obj[0x25];
}
