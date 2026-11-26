class CServerSettings {
public:
    unsigned short GetUShort4BA();

    /* Object layout: the member at offset 0x4BA sits behind a large block of
       earlier state (world / module / player bookkeeping), so we model it as
       an opaque byte array followed by the 16-bit field itself. */
    unsigned char state[0x4BA];
    unsigned short value_4BA;
};

unsigned short CServerSettings::GetUShort4BA() {
    return value_4BA;
}
