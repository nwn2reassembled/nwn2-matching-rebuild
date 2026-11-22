struct B
{
    char pad[0x6C];        // 108 bytes of padding so that 'field' is at offset 0x6c
    void* field;          // pointer stored in the target structure
};

struct A
{
    int dummy;            // first member occupies 4‑byte slot (offset 0)
    B* ptr_at_4;         // second member, located at offset 4 as required
    void foo(void* arg); // ordinary non‑static member function
};

void A::foo(void* arg)   // out‑of‑line definition
{
    ptr_at_4->field = arg;
}

