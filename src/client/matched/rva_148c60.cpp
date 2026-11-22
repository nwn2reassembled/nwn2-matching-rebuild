struct Bar;

class Outer {
public:
    unsigned int getValue() const;
private:
    int dummy_;
    Bar* ptr_;
};

unsigned int Outer::getValue() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(ptr_) + 0x1006c);
}

