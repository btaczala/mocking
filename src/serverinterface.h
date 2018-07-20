#ifndef SERVERINTERFACE_H_ABWSB4LN
#define SERVERINTERFACE_H_ABWSB4LN

namespace interface {
struct ServerInterface {
    virtual ~ServerInterface() {}
    virtual bool startServer() = 0;
};

}  // namespace interface

#endif /* end of include guard: SERVERINTERFACE_H_ABWSB4LN */
