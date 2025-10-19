#include "MyCxxModule.hpp"
#include "utils.hpp"
#include <react/bridging/Bridging.h>

using namespace facebook;

namespace mycxxmodule {

MyCxxModule::MyCxxModule(
    std::shared_ptr<react::CallInvoker> jsInvoker)
    : TurboModule(MyCxxModule::kModuleName, jsInvoker) {
  callInvoker_ = std::move(jsInvoker);
  methodMap_["addNumbers"] = MethodMetadata{2, &MyCxxModule::addNumbers};
  methodMap_["addStrings"] = MethodMetadata{2, &MyCxxModule::addStrings};
}

jsi::Value MyCxxModule::addNumbers(jsi::Runtime &rt,
                                react::TurboModule &turboModule,
                                const jsi::Value args[],
                                size_t count) {
  auto &thisModule = static_cast<MyCxxModule &>(turboModule);
  auto callInvoker = thisModule.callInvoker_;

  try {
    if (2 != count) {
      throw jsi::JSError(rt, "Expected 2 arguments");
    }

    auto arg0 = args[0].asNumber();
    auto arg1 = args[1].asNumber();
    auto ret = arg0 + arg1;

    return jsi::Value(ret);
  } catch (const jsi::JSError &err) {
    throw err;
  } catch (const std::exception &err) {
    throw jsi::JSError(rt, errorMessage(err));
  }
}

jsi::Value MyCxxModule::addStrings(jsi::Runtime &rt,
                                react::TurboModule &turboModule,
                                const jsi::Value args[],
                                size_t count) {
  auto &thisModule = static_cast<MyCxxModule &>(turboModule);
  auto callInvoker = thisModule.callInvoker_;

  try {
    if (2 != count) {
      throw jsi::JSError(rt, "Expected 2 arguments");
    }

    auto arg0 = args[0].asString(rt).utf8(rt);
    auto arg1 = args[1].asString(rt).utf8(rt);
    auto ret = arg0 + arg1;

    return jsi::String::createFromUtf8(rt, ret);
  } catch (const jsi::JSError &err) {
    throw err;
  } catch (const std::exception &err) {
    throw jsi::JSError(rt, errorMessage(err));
  }
}

} // namespace mycxxmodule
