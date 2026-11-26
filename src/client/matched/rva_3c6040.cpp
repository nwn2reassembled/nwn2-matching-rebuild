class CSomeThing {
public:
    char pad[0xCC];
    int field_0xcc;

    void SetField0xCC(int value);
};

void CSomeThing::SetField0xCC(int value) {
    if (value > 0) {
        field_0xcc = value;
    }
}
