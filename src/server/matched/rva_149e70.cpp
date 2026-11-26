struct MyClass {
    int dummy;                 // offset 0
    void* ptr_at_offset4;      // offset 4
    int get_value() const;
};

// Helper struct to force the compiler to use a direct memory access with
// an offset of 0x10014. The size of the padding array is chosen so that the
// "value" field sits exactly at that displacement.
struct Inner {
    char pad[0x10014];
    int value;
};

int MyClass::get_value() const
{
    return ((Inner*)ptr_at_offset4)->value;   // direct load from [eax+0x10014]
}

