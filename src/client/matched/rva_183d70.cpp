struct Pointee {
    char pad[0x9c];
    int flag;
};

class Foo {
public:
    int __thiscall IsSomethingSet();
    char pad[0x108];
    Pointee* m_ptr;
};

int Foo::IsSomethingSet() {
    if (m_ptr != 0)
        return m_ptr->flag != 0;
    return 0;
}
