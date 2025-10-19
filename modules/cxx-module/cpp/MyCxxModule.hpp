#pragma once

#include <memory>
#include <ReactCommon/TurboModule.h>
#include <jsi/jsi.h>

namespace mycxxmodule {

class JSI_EXPORT MyCxxModule : public facebook::react::TurboModule {
public:
  static constexpr const char *kModuleName = "MyCxxModule";

  MyCxxModule(std::shared_ptr<facebook::react::CallInvoker> jsInvoker);

  static facebook::jsi::Value
  addNumbers(facebook::jsi::Runtime &rt,
      facebook::react::TurboModule &turboModule,
      const facebook::jsi::Value args[], size_t count);

  static facebook::jsi::Value
  addStrings(facebook::jsi::Runtime &rt,
      facebook::react::TurboModule &turboModule,
      const facebook::jsi::Value args[], size_t count);

protected:
  std::shared_ptr<facebook::react::CallInvoker> callInvoker_;
};

} // namespace mycxxmodule
