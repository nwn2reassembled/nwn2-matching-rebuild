struct Legacy {
    Legacy* get_this();
};

Legacy* Legacy::get_this() { return this; }
