struct NPCState {
    unsigned char data[0x836];
};

unsigned int GetNPCStateSize() {
    return sizeof(NPCState);
}
