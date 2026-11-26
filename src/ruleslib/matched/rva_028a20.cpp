struct CharacterCreateInfo {
    unsigned char pad[0x18C];
};

unsigned int GetCharacterCreateInfoSize() {
    CharacterCreateInfo cci;
    return sizeof(cci);
}
