struct ServerObj {
    char pad[0x314];
    char field314;

    char* GetField314();
};

char* ServerObj::GetField314() {
    return &this->field314;
}
