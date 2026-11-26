struct Pair {
    unsigned int first;
    unsigned int second;
};

void __stdcall CopyPair(Pair* dst, const Pair* src) {
    if (dst) {
        dst->first = src->first;
        dst->second = src->second;
    }
}
