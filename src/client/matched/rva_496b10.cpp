struct Range {
    int limit;
    const int* base;
    bool Contains(int index) const;
};

bool Range::Contains(int index) const {
    return base != 0 && index >= 0 && index < limit;
}
