struct Entry {
    unsigned char pad[0x115];
    bool active;
    unsigned char tail[0xE];
};

class Thing {
public:
    bool GetFlag(unsigned char index);
};

bool Thing::GetFlag(unsigned char index)
{
    if (index >= 4)
        return false;
    return ((Entry*)this)[index].active;
}
