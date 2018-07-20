#ifndef DATABASEINTERFACE_H_YCFKXGRB
#define DATABASEINTERFACE_H_YCFKXGRB

namespace interface {
struct DatabaseInterface {
    virtual ~DatabaseInterface() {}
    virtual bool initConnection() = 0;
};

}  // namespace interface

#endif /* end of include guard: DATABASEINTERFACE_H_YCFKXGRB */
