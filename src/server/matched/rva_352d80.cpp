class Table {
public:
    unsigned char get(unsigned char index) const;
private:
    unsigned char unused[136];
    unsigned char data[10];
};

unsigned char Table::get(unsigned char index) const
{
    if (index >= 10)
        return 0;
    return data[index];
}
