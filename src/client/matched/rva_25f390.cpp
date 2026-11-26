struct EngineState {
    unsigned int prefix[22]; // 0x00..0x54
    unsigned int state;      // 0x58
};

int __stdcall IsStateAllowed(EngineState* state)
{
    unsigned int v = state->state;
    if (v == 1 || v == 3 || v == 5 || v == 6 || v == 7 || v == 10)
        return 1;
    return 0;
}
