class nwn2server_app
{
public:
    int state;
    unsigned int flags;

    nwn2server_app* self();
};

nwn2server_app* nwn2server_app::self()
{
    return this;
}

typedef nwn2server_app* (nwn2server_app::*self_fn_t)();

static self_fn_t g_self_fn = &nwn2server_app::self;
