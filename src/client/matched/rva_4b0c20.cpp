struct Entry {
    int id;
    unsigned char kind;
    unsigned char level;

    bool Matches(const Entry& other);
};

bool Entry::Matches(const Entry& other) {
    return kind == other.kind && level == other.level;
}
