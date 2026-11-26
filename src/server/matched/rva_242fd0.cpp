struct Entry
{
    unsigned char bytes[180];
};

class Table
{
public:
    Entry* At(int index);

private:
    Entry entries[1];
};

Entry* Table::At(int index)
{
    return &entries[index];
}
