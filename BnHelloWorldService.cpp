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

void BnHelloWorldService::instantiate() {
    android::defaultServiceManager()->addService(
            IHelloWorldService::descriptor, new BnHelloWorldService());
}

status_t BnHelloWorldService::onTransact(uint32_t code,
            const Parcel &data,
            Parcel *reply,
            uint32_t flags) {
    LOGE("OnTransact(%u, %u)", code, flags);

    switch(code) {
        case PRINT: {
            CHECK_INTERFACE(IHelloWorldService, data, reply);
            const char *str = data.readCString();
            print(str);
            return android::NO_ERROR;
        }
        default: {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
    return android::NO_ERROR;    
}

void BnHelloWorldService::print(const char * str) {
    LOGE("Receive string: %s\n", str);
    printf("Receive string: %s\n", str);
}

