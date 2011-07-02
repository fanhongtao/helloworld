/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-06-28
 */

#define LOG_TAG "HelloWorldClient"

#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <utils/Log.h>

#include "IHelloWorldService.h"

int main(int argc, char *argv[]) {
    LOGI("Client start");

    android::sp<android::IServiceManager> sm = android::defaultServiceManager();
    android::sp<android::IBinder> binder= sm->getService(android::String16(SERVICE_NAME));
    if (binder == 0) {
        LOGE("Can't find service: %s", SERVICE_NAME);
        return -1;
    }

    android::sp<IHelloWorldService> shw = android::interface_cast<IHelloWorldService>(binder);
    shw->print("Hello, world.");

    char response[128];
    shw->sayHi("Hi, this is hello-world client", response);
    LOGI("%s\n", response);
    printf("%s\n", response);

    LOGI("Client stop");
    return 0;
}

