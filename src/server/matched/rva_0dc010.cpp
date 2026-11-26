class Object {
public:
    int field_0;
    int state;
    int IsStateValid() const;
};

int Object::IsStateValid() const
{
    int v = state;
    if (v == 0 || v == 1)
        return 1;
    return 0;
}
