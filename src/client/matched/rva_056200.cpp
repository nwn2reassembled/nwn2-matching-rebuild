struct Vec3
{
    float x;
    float y;
    float z;
};

struct Object
{
    char pad[0x210];
    float x;
    float y;
    float z;

    void SetPosition(const Vec3* p);
};

void Object::SetPosition(const Vec3* p)
{
    x = p->x;
    y = p->y;
    z = p->z;
}
