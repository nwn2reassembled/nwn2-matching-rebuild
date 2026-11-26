struct C { int m; C* Reset(); };

C* C::Reset()
{
    m = 0;
    return this;
}
