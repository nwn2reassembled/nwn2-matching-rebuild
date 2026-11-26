struct Thing {
    int field0;
    int field4;
    int field8;
    int fieldC;

    int GetField(unsigned int which);
};

int Thing::GetField(unsigned int which) {
    if (which == 0)
        return field8;
    if (which == 1)
        return fieldC;
    return 0;
}
