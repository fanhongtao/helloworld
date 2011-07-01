/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-06-28
 */

#define LOG_TAG "HelloWorldServer"

#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <utils/Log.h>

#include "IHelloWorldService.h"

int main(int argc, char *argv[]) {
    LOGI("Hello world service start");

	BnHelloWorldService::instantiate();
	android::ProcessState::self()->startThreadPool();
	android::IPCThreadState::self()->joinThreadPool();

    LOGI("Hello world service stop");
	return(0);
}

