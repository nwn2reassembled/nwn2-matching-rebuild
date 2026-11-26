struct Legacy {
    int* data;
    bool check() const;
};

bool Legacy::check() const {
    return (*data != 0);
}
