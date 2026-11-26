struct Session {
    int field0;

    Session* Self();
};

Session* Session::Self()
{
    return this;
}
