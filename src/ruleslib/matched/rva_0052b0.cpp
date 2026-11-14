class MyClass {
public:
    int fieldCount;
    int baseValue;

    int compute(int index) const;
};

int MyClass::compute(int index) const
{
    if (baseValue == 0)
        return 0;
    if (index < 0 || index >= fieldCount)
        return 0;
    return baseValue + index * 40;
}

