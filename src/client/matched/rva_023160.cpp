struct Vec3InitResult {
    int value[3];
};

// returns 1 on failure (null input), 0 on success; fills 3 ints
int __cdecl InitValue3(void *out, int value)
{
    int zero = 0;
    if (value == zero) {
        return 1;
    }
    ((int *)out)[0] = value;
    ((int *)out)[1] = zero;
    ((int *)out)[2] = zero;
    return 0;
}
