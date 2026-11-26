struct ListEntry {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
    unsigned int field_C;
    ListEntry* field_10;
};

struct ServerContainer {
    unsigned int field_0;
    unsigned int field_4;
    ListEntry* field_8;
    unsigned int field_C;

    bool PopEntry();
};

bool ServerContainer::PopEntry()
{
    ListEntry* next = this->field_8->field_10;
    if (next != 0) {
        this->field_8 = next;
        return true;
    }
    return false;
}
