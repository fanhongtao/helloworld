/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-06-28
 */

#define LOG_TAG "HelloWorldService"

#include "IHelloWorldService.h"
#include <binder/IServiceManager.h>
#include <utils/String16.h>
#include <utils/Log.h>
#include <string.h>

using namespace android;

class BpHelloWorldService : public BpInterface<IHelloWorldService> {
public:
    BpHelloWorldService(const sp<IBinder>& impl) : BpInterface<IHelloWorldService>(impl) {
    } 

    void print(const char * str) {
        Parcel data, reply;
        data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor());
        data.writeCString(str);
        remote()->transact(PRINT, data, &reply, IBinder::FLAG_ONEWAY);
    }
}; 


IMPLEMENT_META_INTERFACE(HelloWorldService, SERVICE_NAME);

