class ServerObject {
    unsigned int field_00;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0C;
    unsigned int field_10;
    unsigned int field_14;
public:
    unsigned int GetField14();
};

unsigned int ServerObject::GetField14() {
    return field_14;
}
