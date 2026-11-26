struct Elem {
    int data[92];
};

void CopyElems(Elem* dst, Elem* end, Elem* src)
{
    if (dst != end) {
        do {
            *dst = *src;
            ++dst;
        } while (dst != end);
    }
}
