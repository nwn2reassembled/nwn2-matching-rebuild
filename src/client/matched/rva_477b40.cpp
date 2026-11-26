class Legacy {
public:
    void clearFields();
};

void Legacy::clearFields() {
    // Store zero at offset 0x324 from the object pointer.
    *((int*)((char*)this + 0x324)) = 0;
    // Store zero at offset 0x328 from the object pointer.
    *((int*)((char*)this + 0x328)) = 0;
}

