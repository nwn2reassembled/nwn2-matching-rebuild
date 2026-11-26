struct Controller {
    unsigned char pad0[0xDC];
    int charge;

    void ResetChargeIfPositive();
};

void Controller::ResetChargeIfPositive()
{
    if (charge > 0)
        charge = 0;
}
