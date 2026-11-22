struct Target{
    char padding[0x29c];
    int zero;
};

class Container{
public:
    void func();
private:
    int dummy;
    Target* ptr;
};

void Container::func(){
    this->ptr->zero=0;
}
