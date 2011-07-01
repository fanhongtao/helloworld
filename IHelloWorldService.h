/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-06-28
 */

#ifndef I_HELLOWORLD_SERVICE_H
#define I_HELLOWORLD_SERVICE_H

#include <binder/IInterface.h>
#include <binder/Parcel.h>

#define SERVICE_NAME "test.helloworld"

enum {
    PRINT = 1
};

using namespace android;

class IHelloWorldService : public IInterface {
public:
    DECLARE_META_INTERFACE(HelloWorldService);
    virtual void print(const char * str) = 0;
};

class BnHelloWorldService : public BnInterface<IHelloWorldService> {
public:
    static void instantiate();
    virtual status_t onTransact(uint32_t code,
            const Parcel &data,
            Parcel *reply,
            uint32_t flags);

    void print(const char * str);
}; 

#endif  // I_HELLOWORLD_SERVICE_H
