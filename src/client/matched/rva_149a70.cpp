class Counter {
public:
    unsigned long *m_items;
    int m_count;

    int CountOf(const unsigned long *value);
};

int Counter::CountOf(const unsigned long *value)
{
    int result = 0;
    if (this->m_count > 0) {
        unsigned long *it = this->m_items;
        unsigned long needle = *value;
        int remaining = this->m_count;
        do {
            if (*it == needle) {
                result = result + 1;
            }
            it = it + 1;
            remaining = remaining - 1;
        } while (remaining != 0);
    }
    return result;
}
