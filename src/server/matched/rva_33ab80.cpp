struct ServerObject
{
    char reserved_0[0x2eb0];
    int field_2eb0;
    char reserved_1[8];
    int field_2ebc;

    void ClearFields();
};

void ServerObject::ClearFields()
{
    int zero = 0;
    field_2eb0 = zero;
    field_2ebc = zero;
}
