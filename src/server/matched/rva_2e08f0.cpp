class Thing {
public:
    int fields[4];
    int field16;

    int GetField16();
};

int Thing::GetField16() {
    return field16;
}
