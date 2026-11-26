// Target: NWN2RulesLib.dll RVA 0x34530 (6 bytes, no fixups)

static const int kClassSize = 0x48;

class SomeRulesObject {
public:
    unsigned int field0;   // +0x00
    unsigned int field1;   // +0x04
    unsigned int field2;   // +0x08
    unsigned int field3;   // +0x0C
    void* field4;          // +0x10
    void* field5;          // +0x14
    void* field6;          // +0x18
    unsigned int field7;   // +0x1C
    unsigned int field8;   // +0x20
    void* field9;          // +0x24
    void* field10;         // +0x28
    void* field11;         // +0x2C
    unsigned int field12;  // +0x30
    unsigned int field13;  // +0x34
    void* field14;         // +0x38
    void* field15;         // +0x3C
    unsigned int field16;  // +0x40
    unsigned int field17;  // +0x44
};

// Object-size query thunk: loads the class size constant into eax and returns.
// Body is a plain `mov eax, 0x48; ret`, so no argument is read and no
// stack cleanup beyond the return is performed.

unsigned int __cdecl GetRulesObjectSize()
{
    return sizeof(SomeRulesObject); // 0x48
}
