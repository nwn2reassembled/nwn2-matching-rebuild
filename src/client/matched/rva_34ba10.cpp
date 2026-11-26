class CGame {
public:
    char pad0_08b4[0x08b4];
    bool field_8b4;
    char pad_08b5[0x968 - 0x8b5];
    unsigned short field_968;
    char pad_096a[0x9e4 - 0x96a];
    int field_9e4;

    bool CanDoThing();
};

bool __thiscall CGame::CanDoThing() {
    if (this->field_9e4 != 0)
        return false;
    if (this->field_968 == 0)
        return false;
    return this->field_8b4;
}
