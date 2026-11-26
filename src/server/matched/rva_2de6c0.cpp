struct Data
{
    char reserved[0x1390];
    int value;
    char reserved2[0x139c - 0x1394];
    short flag;
};

class Container
{
public:
    Data* m_data;

    void GetData(int* value, short* flag);
};

void Container::GetData(int* value, short* flag)
{
    Data* data = m_data;
    *value = data->value;
    *flag = data->flag;
}
