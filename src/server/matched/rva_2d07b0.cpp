struct ServerSession {
    int state;
    char padding[0x28];

    ServerSession* Self();
};

ServerSession* ServerSession::Self() {
    return this;
}
