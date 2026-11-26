struct CopyData
{
    int value00;
    int value04;
    int value08;
    int value0C;
    int value10;
    int value14;
    int value18;
    int value1C;
    int value20;
    int value24;
    int value28;
    char flag2C;
    int value30;
    int value34;
    int value38;
    int value3C;

    void CopyFrom(const CopyData* other);
};

void CopyData::CopyFrom(const CopyData* other)
{
    value00 = other->value00;
    value04 = other->value04;
    value08 = other->value08;
    value0C = other->value0C;
    value10 = other->value10;
    value14 = other->value14;
    value3C = other->value3C;
    value38 = other->value38;
    value18 = other->value18;
    value1C = other->value1C;
    value20 = other->value20;
    value24 = other->value24;
    value28 = other->value28;
    flag2C = other->flag2C;
    value30 = other->value30;
    value34 = other->value34;
}
