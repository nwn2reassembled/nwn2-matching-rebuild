class Item {
public:
    unsigned char hasId;
    unsigned char pad0[0xB];
    int id;
    unsigned char padC[0x44];
    int resolvedId;

    int GetId();
};

int Item::GetId() {
    if (hasId != 0)
        return id;
    return resolvedId;
}
