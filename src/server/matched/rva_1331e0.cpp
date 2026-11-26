struct ServerState {
    unsigned char pad[0x1BB8];
    int sessionCount;
};

int __cdecl ServerTickSessionCount(ServerState *state) {
    int previous = state->sessionCount;
    int next = previous + 1;
    state->sessionCount = next;
    if (next < 0) {
        state->sessionCount = 0;
    }
    return previous;
}
