use crate::ffi::bridging::*;
use crate::generated::*;
use crate::types::*;

pub struct MyCrabyModule {
    id: usize,
}

impl MyCrabyModuleSpec for MyCrabyModule {
    fn new(id: usize) -> MyCrabyModule {
        MyCrabyModule { id }
    }

    fn id(&self) -> usize {
        self.id
    }

    fn add_numbers(&self, a: Number, b: Number) -> Number {
        a + b
    }

    fn add_strings(&self, a: String, b: String) -> String {
        [a, b].concat()
    }
}
