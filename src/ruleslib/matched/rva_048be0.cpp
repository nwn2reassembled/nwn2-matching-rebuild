class NWN2RulesObject {
public:
    unsigned int GetField14() const;

private:
    unsigned char pad_00[0x14];
    unsigned int field_14;
};

unsigned int __thiscall NWN2RulesObject::GetField14() const {
    return field_14;
}
