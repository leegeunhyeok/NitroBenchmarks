import { NativeModule, NativeModuleRegistry } from "craby-modules";

export interface Spec extends NativeModule {
  addNumbers(a: number, b: number): number
  addStrings(a: string, b: string): string
}

export default NativeModuleRegistry.get<Spec>('MyCrabyModule') as Spec | null
