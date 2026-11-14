struct MyStruct {
    unsigned char pad[120];
    short field78;
    short field7a;
    unsigned char compute() const;
};

unsigned char MyStruct::compute() const {
    short f1 = field78;
    unsigned char dl;
    if (f1 <= 30) {
        dl = 5;
    } else {
        unsigned char tmp1 = f1 < 70;
        dl = ((tmp1 - 1) & 3) + 1;
    }
    short f2 = field7a;
    unsigned char cl;
    if (f2 <= 30) {
        cl = 3;
    } else {
        unsigned char tmp2 = f2 >= 70;
        cl = tmp2 + 1;
    }
    unsigned char al = 0;
    if (cl == 1)
        al = 3;
    else if (cl == 3)
        al = 6;
    if (dl == 1)
        al += dl;
    else if (dl == 5)
        al += 2;
    return al;
}
