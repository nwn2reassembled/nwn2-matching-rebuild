struct Legacy {
    Legacy* retain(int unused);
};

Legacy* Legacy::retain(int unused) {
    return this;
}
