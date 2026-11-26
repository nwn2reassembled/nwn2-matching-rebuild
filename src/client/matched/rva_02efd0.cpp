struct Payload {
    char reserved[0x28];
    unsigned int value;
};

struct Target {
    char reserved[8];
    Payload* payload;

    void SetPayloadValue(unsigned char value);
};

void Target::SetPayloadValue(unsigned char value) {
    if (payload != 0) {
        payload->value = value;
    }
}
