struct Widget {
    unsigned int field_0;
    int active;
    int value;
    int GetValue();
};

int Widget::GetValue() {
    if (this->active != 0) {
        return this->value;
    }
    return 0;
}
