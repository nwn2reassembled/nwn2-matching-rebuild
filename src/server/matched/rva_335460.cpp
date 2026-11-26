class ServerObj {
public:
    char pad_0000[0x324];
    unsigned int field_324;
    unsigned int field_328;

    void Clear();
};

void ServerObj::Clear() {
    field_324 = 0;
    field_328 = 0;
}
