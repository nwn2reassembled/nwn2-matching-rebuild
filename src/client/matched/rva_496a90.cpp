class Thing {
    unsigned int field0;
    unsigned int id;
public:
    int IsSpecial() const;
};

int Thing::IsSpecial() const {
    if (this->id == 0xe)
        return 1;
    if (this->id == 0x38)
        return 1;
    return this->id == 0x39;
}
