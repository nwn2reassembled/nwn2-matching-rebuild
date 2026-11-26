struct ServerObject {
    unsigned char pad[0x3F0];
    int stateFlags;

    int GetStateFlags();
};

int ServerObject::GetStateFlags() {
    return stateFlags;
}
