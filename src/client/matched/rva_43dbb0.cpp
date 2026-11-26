struct Dummy {
    char pad[124];
    int field;
    int* getField();
};

int* Dummy::getField() { return &field; }
