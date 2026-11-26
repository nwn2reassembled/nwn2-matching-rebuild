class CRuleTable {
public:
    void __stdcall SetField(unsigned char value);

    char  m_name[8];
    int   m_a;
    int   m_b;
    int   m_c;
    unsigned char field_14;
};

void CRuleTable::SetField(unsigned char value)
{
    if (value <= 4)
        field_14 = value;
}
