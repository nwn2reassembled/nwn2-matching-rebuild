class RulesEngine {
public:
    /* 0x00 */ void* vtable;
    /* 0x04 */ char pad04[0x14];
    /* 0x18 */ unsigned int flags;

    unsigned int GetFlags();
};

unsigned int RulesEngine::GetFlags() {
    return this->flags;
}
