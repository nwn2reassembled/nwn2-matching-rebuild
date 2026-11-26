struct Bounds
{
    short x;
    short y;
    short w;
    short h;

    bool Overlaps(const Bounds* other);
};

bool Bounds::Overlaps(const Bounds* other)
{
    if ((short)(this->w + this->x) < other->x)
        return false;
    if ((short)(this->h + this->y) < other->y)
        return false;
    if ((short)(other->w + other->x) < this->x)
        return false;
    if ((short)(other->h + other->y) >= this->y)
        return true;
    return false;
}
