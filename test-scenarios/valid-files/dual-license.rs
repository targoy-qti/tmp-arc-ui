// Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
// SPDX-License-Identifier: Unicode-3.0 OR BSD-3-Clause OR GPL-2.0 OR LGPL-2.1

//! This file demonstrates a multi-level license with multiple options.
//! Users can choose to use this code under any of the following licenses:
//! - Unicode-3.0
//! - BSD-3-Clause
//! - GPL-2.0
//! - LGPL-2.1
//! This provides maximum flexibility for different use cases and requirements.

use std::collections::HashMap;

/// A simple key-value store implementation
pub struct KeyValueStore {
    data: HashMap<String, String>,
}

impl KeyValueStore {
    /// Creates a new empty KeyValueStore
    pub fn new() -> Self {
        KeyValueStore {
            data: HashMap::new(),
        }
    }

    /// Inserts a key-value pair into the store
    pub fn insert(&mut self, key: String, value: String) {
        self.data.insert(key, value);
    }

    /// Retrieves a value by key
    pub fn get(&self, key: &str) -> Option<&String> {
        self.data.get(key)
    }

    /// Removes a key-value pair from the store
    pub fn remove(&mut self, key: &str) -> Option<String> {
        self.data.remove(key)
    }

    /// Returns the number of items in the store
    pub fn len(&self) -> usize {
        self.data.len()
    }

    /// Checks if the store is empty
    pub fn is_empty(&self) -> bool {
        self.data.is_empty()
    }
}

impl Default for KeyValueStore {
    fn default() -> Self {
        Self::new()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_insert_and_get() {
        let mut store = KeyValueStore::new();
        store.insert("name".to_string(), "Qualcomm".to_string());
        assert_eq!(store.get("name"), Some(&"Qualcomm".to_string()));
    }

    #[test]
    fn test_remove() {
        let mut store = KeyValueStore::new();
        store.insert("key".to_string(), "value".to_string());
        assert_eq!(store.remove("key"), Some("value".to_string()));
        assert_eq!(store.get("key"), None);
    }

    #[test]
    fn test_len() {
        let mut store = KeyValueStore::new();
        assert_eq!(store.len(), 0);
        store.insert("key1".to_string(), "value1".to_string());
        assert_eq!(store.len(), 1);
    }
}
