struct StateBlock {
    unsigned char bytes[0x701];
};

class ServerObject {
    char pad[0xA4];
    StateBlock* state;
public:
    unsigned char GetPhaseFlag();
};

unsigned char ServerObject::GetPhaseFlag() {
    unsigned char v = state->bytes[0x701];
    switch (v) {
    case 7:
        return 3;
    case 8:
        return 6;
    default:
        return 0;
    }
}
