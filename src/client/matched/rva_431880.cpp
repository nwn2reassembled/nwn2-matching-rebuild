class Legacy {
public:
    int clearFields();
private:
    char pad1[0x70];
    int field1;
    char pad2[0x1C];
    int field2;
};

int Legacy::clearFields() {
    field2 = 0;
    field1 = 0;
    return 0;
}

