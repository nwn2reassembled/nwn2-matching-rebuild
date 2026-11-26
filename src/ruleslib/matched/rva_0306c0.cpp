class RuleSet {
    unsigned char data[8];
    unsigned short value;

public:
    void __stdcall SetValue(unsigned short newValue);
};

void RuleSet::SetValue(unsigned short newValue)
{
    if (this) {
        this->value = newValue;
    }
}
