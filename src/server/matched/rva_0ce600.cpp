void FillRangeFromInt(int* first, int* last, int* valueSource) {
    if (first == last)
        return;
    for (; first != last; ++first)
        *first = *valueSource;
}
