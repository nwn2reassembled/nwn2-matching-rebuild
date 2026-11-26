class C {
public:
    unsigned short GetValue() const;
private:
    char padding_[0x3d0];
    unsigned short value_;
};

unsigned short C::GetValue() const
{
    return value_;
}
