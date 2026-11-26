struct Vec3 {
    int x;
    int y;
    int z;
};

struct Xform {
    Vec3 t;
    int flags;
};

void InitXform(Xform* out, Vec3 translation)
{
    out->t.x = translation.x;
    out->t.y = translation.y;
    out->t.z = translation.z;
    out->flags = 0;
}
