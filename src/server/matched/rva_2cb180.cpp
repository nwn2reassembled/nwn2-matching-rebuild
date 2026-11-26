struct Config {
    char pad[0x398];
    int field_398;

    int& GetField398();
};

int& Config::GetField398() {
    return this->field_398;
}
