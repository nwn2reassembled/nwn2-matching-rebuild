struct Vec3
{
    float x;
    float y;
    float z;
};

class Container
{
    char padding[0x544];
    Vec3 values[1];

public:
    void copy(int index, const Vec3& value);
};

void Container::copy(int index, const Vec3& value)
{
    Vec3* destination = &values[index];
    destination->x = value.x;
    destination->y = value.y;
    destination->z = value.z;
}
