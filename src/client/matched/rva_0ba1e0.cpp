struct Legacy {
    Legacy* self();
};

Legacy* Legacy::self() { return this; }

