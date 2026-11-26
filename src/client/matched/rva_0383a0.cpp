struct Vec3 {
    float x;
    float y;
    float z;
    Vec3* Assign(const Vec3* other);
};

Vec3* Vec3::Assign(const Vec3* other) {
    x = other->x;
    y = other->y;
    z = other->z;
    return this;
}
