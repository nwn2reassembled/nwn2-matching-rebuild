struct Pair {
    int reserved[10];
    int first_;
    int second_;

    int Set(int first, int second);
};

int Pair::Set(int first, int second) {
    first_ = first;
    second_ = second;
    return 0;
}
