#ifndef DATABASEINTERFACE_H_YCFKXGRB
#define DATABASEINTERFACE_H_YCFKXGRB

struct DatabaseInterface {

    virtual ~DatabaseInterface() {}
    virtual bool initConnection() = 0;
};

#endif /* end of include guard: DATABASEINTERFACE_H_YCFKXGRB */
