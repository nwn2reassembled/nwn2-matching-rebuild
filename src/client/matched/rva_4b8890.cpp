struct Record {
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
    int f5;
    int f6;
    int f7;
    int f8;
    int f9;
    int f10;
    char f11;
    int f12;
    int f13;
    int f14;
    int f15;

    void CopyFrom(const Record& other);
};

void Record::CopyFrom(const Record& other)
{
    f0 = other.f0;
    f1 = other.f1;
    f2 = other.f2;
    f3 = other.f3;
    f4 = other.f4;
    f5 = other.f5;
    f15 = other.f15;
    f14 = other.f14;
    f6 = other.f6;
    f7 = other.f7;
    f8 = other.f8;
    f9 = other.f9;
    f10 = other.f10;
    f11 = other.f11;
    f12 = other.f12;
    f13 = other.f13;
}
