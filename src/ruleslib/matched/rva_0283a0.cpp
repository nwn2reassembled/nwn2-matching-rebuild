// NWN2RulesLib.dll RVA 0x283a0
// L00: mov eax, 0xd4 ; ret
// Returns the constant 212 (0xd4) in EAX with no stack frame;
// the immediate constant is not a relocation, so no fixups are present.

// A plausible role: a small accessor reporting a fixed table/record size
// (e.g. sizeof of a rules-engine record or a row stride).

struct RulesRecord
{
    unsigned char data[212]; // sizeof(RulesRecord) == 0xd4 (212)
};

int GetRulesRecordSize()
{
    return sizeof(RulesRecord);
}
