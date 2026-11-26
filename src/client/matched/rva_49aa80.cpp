struct Thing {
    char pad[0x88];
    char field88[10];

    void SetField(unsigned char index, unsigned char value);
};

void Thing::SetField(unsigned char index, unsigned char value)
{
    if (index < 10) {
        field88[index] = value;
    }
}
