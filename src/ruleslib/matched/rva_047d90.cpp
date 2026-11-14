struct LegacyObject {
    char pad[28];
    int counter;
    void update();
};

void LegacyObject::update() {
    if (counter <= 1) {
        counter = 0;
    } else {
        --counter;
    }
}
