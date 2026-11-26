struct ServerObject {
    int id;
    int flags;

    ServerObject& Self();
};

ServerObject& ServerObject::Self() {
    return *this;
}
