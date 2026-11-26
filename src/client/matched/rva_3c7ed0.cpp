struct Legacy {
    int a;
    int b;
    int c;
    void update();
};

void Legacy::update() {
    this->c = this->b;
}

