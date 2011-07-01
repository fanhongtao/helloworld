LOCAL_PATH := $(call my-dir)
BASE_SHARED_LIBARIES := libutils liblog libc libui libbinder

#----------------- helloworld_service begin
include $(CLEAR_VARS)

LOCAL_MODULE := helloworld_service
LOCAL_MODULE_PATH := $(TARGET_OUT)/bin

LOCAL_SHARED_LIBRARIES = $(BASE_SHARED_LIBARIES)

LOCAL_SRC_FILES := BnHelloWorldService.cpp  BpHelloWorldService.cpp

include $(BUILD_SHARED_LIBRARY)
#----------------- helloworld_client end


#----------------- helloworld_client begin
include $(CLEAR_VARS)

LOCAL_MODULE := helloworld_client
LOCAL_MODULE_PATH := $(TARGET_OUT)/bin

LOCAL_SHARED_LIBRARIES = $(BASE_SHARED_LIBARIES)  libhelloworld_service

LOCAL_SRC_FILES := HelloWorldClient.cpp

include $(BUILD_EXECUTABLE)
#----------------- helloworld_client end


#----------------- helloworld_server begin
include $(CLEAR_VARS)

LOCAL_MODULE := helloworld_server
LOCAL_MODULE_PATH := $(TARGET_OUT)/bin

LOCAL_SHARED_LIBRARIES = $(BASE_SHARED_LIBARIES)  libhelloworld_service

LOCAL_SRC_FILES := HelloWorldServer.cpp

include $(BUILD_EXECUTABLE)
#----------------- helloworld_server end

