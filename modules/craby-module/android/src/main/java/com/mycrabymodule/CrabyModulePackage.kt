package com.mycrabymodule

import com.facebook.hermes.reactexecutor.HermesExecutor
import com.facebook.react.BaseReactPackage
import com.facebook.react.bridge.NativeModule
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.module.model.ReactModuleInfo
import com.facebook.react.module.model.ReactModuleInfoProvider
import com.facebook.soloader.SoLoader

import java.util.HashMap

class MyCrabyModulePackage : BaseReactPackage() {
  init {
    SoLoader.loadLibrary("cxx-my-craby-module")
  }

  override fun getModule(name: String, reactContext: ReactApplicationContext): NativeModule? {
    return null
  }

  override fun getReactModuleInfoProvider(): ReactModuleInfoProvider {
    return ReactModuleInfoProvider {
      val moduleInfos: MutableMap<String, ReactModuleInfo> = HashMap()
      moduleInfos
    }
  }
}
