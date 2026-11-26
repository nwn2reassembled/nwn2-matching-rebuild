struct Float14 {
    float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13;
    Float14& operator=(const Float14& other);
};

Float14& Float14::operator=(const Float14& other)
{
    f0 = other.f0;
    f1 = other.f1;
    f2 = other.f2;
    f4 = other.f4;
    f5 = other.f5;
    f6 = other.f6;
    f3 = other.f3;
    f7 = other.f7;
    f8 = other.f8;
    f9 = other.f9;
    f10 = other.f10;
    f11 = other.f11;
    f12 = other.f12;
    f13 = other.f13;
    return *this;
}
