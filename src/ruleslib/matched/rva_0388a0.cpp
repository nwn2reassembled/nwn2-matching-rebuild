class X {
public:
    unsigned int get(const struct Y* p) const;
};

struct Y { char pad[12]; unsigned int value; };

unsigned int X::get(const Y* p) const { return p->value; }

