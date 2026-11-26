class CNX {
public:
    unsigned char pad[0x9c];
    int field_9c;
};

class CThing {
public:
    unsigned char pad[0x1d8];
    CNX* slots[39];
    void SetSlotsField9c(int value);
};

void CThing::SetSlotsField9c(int value)
{
    CNX** p = &slots[1];
    for (int i = 13; i != 0; --i) {
        CNX* a = p[-1];
        if (a != 0)
            a->field_9c = value;
        CNX* b = p[0];
        if (b != 0)
            b->field_9c = value;
        CNX* c = p[1];
        if (c != 0)
            c->field_9c = value;
        p += 3;
    }
}
