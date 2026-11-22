struct Legacy {
    int dummy;
    int data;
    int get_data() const;
};

int Legacy::get_data() const { return data; }
