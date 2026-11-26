struct Point {
    short x;
    short y;
};

struct Rect {
    short x;
    short y;
    short width;
    short height;
};

class WidgetContainer {
public:
    bool ContainsPoint(const Point* point);
    // ...
    char pad_[0x12C];   // other members precede these fields
    Rect** rects_;      // offset 0x12C
    int rectCount_;     // offset 0x130
};

bool WidgetContainer::ContainsPoint(const Point* point)
{
    for (int i = 0; i < rectCount_; ++i) {
        const Rect* r = rects_[i];
        if (point->x < r->x)
            continue;
        if (point->x > r->x + r->width)
            continue;
        if (point->y < r->y)
            continue;
        if (point->y > r->y + r->height)
            continue;
        return true;
    }
    return false;
}
