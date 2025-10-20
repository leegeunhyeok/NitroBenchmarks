use crate::ffi::bridging::*;
use crate::generated::*;
use crate::types::*;

pub struct MyCrabyModule {
    id: usize,
}

impl MyCrabyModuleSpec for MyCrabyModule {
    fn new(id: usize) -> Self {
        MyCrabyModule { id }
    }

    fn id(&self) -> usize {
        self.id
    }

    fn add_numbers(&mut self, a: Number, b: Number) -> Number {
        a + b
    }

    fn add_strings(&mut self, a: &str, b: &str) -> String {
        let mut s = String::with_capacity(a.len() + b.len());
        s.push_str(a);
        s.push_str(b);
        s
    }
}
