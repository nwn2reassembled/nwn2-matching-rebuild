struct U64
{
    unsigned __int64 value;
};

int AddTo(U64* result, const U64* left, const U64* right)
{
    result->value = left->value + right->value;
    return 0;
}
