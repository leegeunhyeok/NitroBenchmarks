#include <MyCxxModule.hpp>

#include <jni.h>
#include <ReactCommon/CxxTurboModuleUtils.h>

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
  facebook::react::registerCxxModuleToGlobalModuleMap(
      mycxxmodule::MyCxxModule::kModuleName,
      [](std::shared_ptr<facebook::react::CallInvoker> jsInvoker) {
        return std::make_shared<mycxxmodule::MyCxxModule>(jsInvoker);
      });
  return JNI_VERSION_1_6;
}
