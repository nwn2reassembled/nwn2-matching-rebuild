struct Element {
    char reserved[0x114];
    int value;
};

struct Manager {
    char reserved[0x30];
    Element** elements;
};

struct Owner {
    char reserved[0x20];
    unsigned int index;
    int GetValue();
};

int Owner::GetValue() {
    Manager* manager = *reinterpret_cast<Manager**>(0x86ac78);
    return manager->elements[index & 0xffff]->value;
}
