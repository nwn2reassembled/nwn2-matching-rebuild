struct LegacyObject {
    char padding[208];
    int field;
    bool isNonZero() const;
};

bool LegacyObject::isNonZero() const {
    return this->field != 0;
}

