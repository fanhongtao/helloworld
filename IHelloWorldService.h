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
    PRINT = 1,
    SAY_HI  = 2
};

using namespace android;

class IHelloWorldService : public IInterface {
public:
    DECLARE_META_INTERFACE(HelloWorldService);

    /**
     * Client send a string to service.
     * Service print/log it. no response.
     * @param[in] str The message send to service.
     */
    virtual void print(const char * message) = 0;

    /**
     * Client send a string to service.
     * Service print/log it, and send a message back to client.
     * @param[in]  message  The message send to service.
     * @param[out] response The response send back to client.
     */
    virtual void sayHi(const char * message, char * response) = 0;
};

class BnHelloWorldService : public BnInterface<IHelloWorldService> {
public:
    static void instantiate();
    virtual status_t onTransact(uint32_t code,
            const Parcel &data,
            Parcel *reply,
            uint32_t flags);

    void print(const char * message);

    void sayHi(const char * message, char * response);
}; 

#endif  // I_HELLOWORLD_SERVICE_H

