struct ZeroPair {
    int first[11];
    int second[11];

    ZeroPair* Clear();
};

ZeroPair* ZeroPair::Clear() {
    for (int i = 0; i < 11; ++i) {
        first[i] = 0;
        second[i] = 0;
    }
    return this;
}
