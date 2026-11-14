struct Legacy {
    unsigned int* ptr;
    bool check() const;
};

bool Legacy::check() const {
    return *ptr != 0;
}
