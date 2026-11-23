struct Arg { unsigned int first; unsigned int second; };

class Legacy {
public:
    void copyFrom(const Arg* arg);
private:
    char pad[36];
    unsigned int field24;
    unsigned int field28;
};

void Legacy::copyFrom(const Arg* arg)
{
    this->field24 = arg->first;
    this->field28 = arg->second;
}
