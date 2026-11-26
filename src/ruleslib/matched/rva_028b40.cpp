// NWN2RulesLib.dll, RVA 0x28B40

// Hard-coded rule constant table value (0x01A5 = 421).
static const int kECLMaxLevel = 421;

// Returns the maximum effective character level allowed by the rules engine.
// Free __cdecl function: takes no arguments, touches no object, returns in EAX.
int GetECLMaxLevel()
{
    return kECLMaxLevel;
}
