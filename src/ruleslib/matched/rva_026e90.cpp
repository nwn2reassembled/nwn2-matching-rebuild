int __stdcall IsValidSelection(int value)
{
    bool result = (value >= 0 && value <= 14) ||
                  value == 0x17 ||
                  value == 0x18 ||
                  value == 0x19 ||
                  value == 0x1a;
    return result;
}
