struct Player {
    unsigned char pad[0x18];
    void *field_18;
};

void __stdcall SetPlayerField18(Player *player, void *value) {
    if (player != 0) {
        player->field_18 = value;
    }
}
