class Widget {
    int pad_[22];
    int count_;
public:
    bool IsActive() const;
};

bool __thiscall Widget::IsActive() const {
    bool result = false;
    if (this->count_ > 0)
        result = true;
    return result;
}
