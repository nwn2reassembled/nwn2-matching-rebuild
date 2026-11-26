struct CGameState {
    unsigned char gap00[0x44];
    unsigned char field44;
    unsigned char gap45[3];
    unsigned int field48;

    void Update();
};

void CGameState::Update() {
    unsigned int state = field48;
    if (state == 2 || state == 0) {
        field48 = 1;
        field44 = 0;
    } else if (state == 3 || state == 1) {
        field48 = 0;
        field44 = 1;
    }
}
