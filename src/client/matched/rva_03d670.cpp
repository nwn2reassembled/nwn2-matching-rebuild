struct Legacy {
    char pad[0x28];
    int field1;
    int field2;

    int clearFields();
};

int Legacy::clearFields() {
    field1 = 0;
    field2 = 0;
    return 0;
}
