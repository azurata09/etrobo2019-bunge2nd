mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS += \
  balancer.o \
  balancer_param.o \

APPL_CXXOBJS += \
  BalancerCpp.o \
  Logger.o \
  TailMotor.o \
  SonarAlerter.o \
  TurnValues.o \
  LineTracer.o \
  Utils.o \
  Tutorial.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIR += \
  ${mkfile_path}Parts/ \
  ${mkfile_path}balancer/ \
  ${mkfile_path}Tasks/ \

INCLUDES += \
  -I${mkfile_path}Parts/ \
  -I${mkfile_path}balancer/ \
  -I${mkfile_path}Tasks/ \
