struct Entry {
    int value;
};

struct Lookup {
    Entry** entries;
    int capacity;
    int count;

    int Count(int value) const;
};

int Lookup::Count(int value) const
{
    int result = 0;
    for (int i = 0; i < count; ++i)
        result += (entries[i]->value == value);
    return result;
}
