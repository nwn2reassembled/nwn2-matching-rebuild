struct Arg {
    char pad[0x7d0];
    int value;
};

class C {
    int field_0;
    int field_4[18];
public:
    int Find(const Arg* arg);
};

int C::Find(const Arg* arg) {
    for (int i = 0; i < 18; ++i) {
        if (field_4[i] == arg->value) {
            return 1 << i;
        }
    }
    return 0;
}
