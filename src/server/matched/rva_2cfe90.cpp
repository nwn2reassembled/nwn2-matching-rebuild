class Session {
public:
    Session* GetSelf();
};

Session* Session::GetSelf() {
    return this;
}
