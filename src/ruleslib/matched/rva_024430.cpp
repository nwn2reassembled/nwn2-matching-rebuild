struct S { char pad[12]; unsigned char flag; };

class C {
public:
    static int __stdcall method(S* param);
};

int C::method(S* param) { return (param->flag & 1); }
