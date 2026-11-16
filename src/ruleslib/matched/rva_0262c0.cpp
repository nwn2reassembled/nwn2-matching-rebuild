struct S {
    char pad[0x1DC];
    int field;
    static int __stdcall get_field(const S* s);
};

int __stdcall S::get_field(const S* s) { return s->field; }

