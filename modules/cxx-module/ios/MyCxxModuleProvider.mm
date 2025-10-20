#import "MyCxxModule.hpp"

#import <ReactCommon/CxxTurboModuleUtils.h>

@interface MyCxxModuleProvider : NSObject
@end

@implementation MyCxxModuleProvider
+ (void)load {
  facebook::react::registerCxxModuleToGlobalModuleMap(
      mycxxmodule::MyCxxModule::kModuleName,
      [](std::shared_ptr<facebook::react::CallInvoker> jsInvoker) {
      return std::make_shared<mycxxmodule::MyCxxModule>(jsInvoker);
      });
}
@end
