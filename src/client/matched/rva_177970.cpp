struct Legacy {
    char pad[0x328];
    void* field;
    void* getField();
};

void* Legacy::getField() {
    return &field;
}

