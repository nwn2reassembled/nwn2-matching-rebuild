struct BalanceEntry {
    char pad[0x78];
    short field78;
    short field7a;

    unsigned char Compute();
};

unsigned char BalanceEntry::Compute()
{
    unsigned char d;
    if (field78 <= 30)
        d = 5;
    else
        d = ((field78 < 70) - 1 & 3) + 1;

    unsigned char c;
    if (field7a <= 30)
        c = 3;
    else
        c = (field7a >= 70) + 1;

    unsigned char result = 0;
    if (c == 1)
        result = 3;
    else if (c == 3)
        result = 6;

    if (d == 1) {
        result = result + d;
        return result;
    }
    if (d == 5) {
        result = result + 2;
    }
    return result;
}
