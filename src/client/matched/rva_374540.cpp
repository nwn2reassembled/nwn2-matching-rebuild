class EntryList {
public:
    int Sum();
private:
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int* items_;
    int field_14;
    int count_;
};

int EntryList::Sum() {
    int total = 0;
    int count = this->count_;
    if (count > 0) {
        int* p = this->items_;
        do {
            total += *p;
            ++p;
            --count;
        } while (count != 0);
    }
    return total;
}
