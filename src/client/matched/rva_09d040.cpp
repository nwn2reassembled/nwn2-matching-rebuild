struct Legacy {
    char pad[192];
    int field;
    int getField() const;
};

int Legacy::getField() const { return field; }
