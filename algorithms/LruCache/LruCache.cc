// Source : https://leetcode.com/problems/lru-cache
// Author : xjliang
// Date   : 2021-03-12

/*****************************************************************************************************
 *
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 * 	LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * 	int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * 	void put(int key, int value) Update the value of the key if the key exists. Otherwise, add
 * the key-value pair to the cache. If the number of keys exceeds the capacity from this operation,
 * evict the least recently used key.
 *
 * Follow up:
 * Could you do get and put in O(1) time complexity?
 *
 * Example 1:
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 * Constraints:
 *
 * 	1 <= capacity <= 3000
 * 	0 <= key <= 3000
 * 	0 <= value <= 104
 * 	At most 3 * 104 calls will be made to get and put.
 ******************************************************************************************************/

// Requirement: do `get` and `put` in `O(1)` time complexity
class LRUCache {
 private:
  struct Node {
    int key;
    int value;
    Node(int k, int v) : key(k), value(v)
    {
    }
  };

 public:
  // initialize the LRU cache with positive size capacity.
  LRUCache(int capacity) : capacity_(capacity) {

  }

  // Return the value of the key if the key exists
  int get(int key) {
    if (map_.find(key) == map_.end()) {
      return -1;
    }
    Node* node = map_[key];
    make_recently(key); // #1
    return node->value;
  }

  // Update the value of the key if the key exists.
  // Otherwise, add the key-value pair to the cache.
  //
  // If the number of keys exceedds the capacity from this operation,
  // evict the least recently used key.
  void put(int key, int value) {
    if (map_.find(key) != map_.end()) {
      delete_key(key);
      add_recently(key, value);
      return ;
    }
    if (map_.size() == capacity_) {
      remove_least_recently();
    }
    add_recently(key, value);
  }

 private:
  void make_recently(int key) {
    Node* node = map_[key];
    cache_.remove(node);
    cache_.push_back(node);
  }

  void add_recently(int key, int value) {
    Node* node = new Node(key, value);
    cache_.push_back(node);
    map_[key] = node;
  }

  void delete_key(int key) {
    Node* node = map_[key];
    cache_.remove(node);
    map_.erase(key);
  }

  void remove_least_recently() {
    Node* node = cache_.front();
    cache_.remove(node);
    map_.erase(node->key);
  }

 private:
  std::list<Node*> cache_;
  std::unordered_map<int, Node*> map_;
  int capacity_;
};

// Solution2
// Requirement: do `get` and `put` in `O(1)` time complexity
class LRUCache {
 private:
   public:
  // initialize the LRU cache with positive size capacity.
  LRUCache(int capacity) : capacity_(capacity) {

  }

  // Return the value of the key if the key exists
  int get(int key) {
    auto it = map_.find(key);
    if (it == map_.end()) {
      return -1;
    }
    cache_.splice(cache_.begin(), cache_, it->second);
    return it->second->second;
  }

  // Update the value of the key if the key exists.
  // Otherwise, add the key-value pair to the cache.
  //
  // If the number of keys exceedds the capacity from this operation,
  // evict the least recently used key.
  void put(int key, int value) {
    auto it = map_.find(key);
    if (it != map_.end()) {
      it->second->second = value;
      cache_.splice(cache_.begin(), cache_, it->second);
      return ;
    }
    if (map_.size() == capacity_) {
      // remove least recently
      int key2del = cache_.back().first;
      map_.erase(key2del);
      cache_.pop_back();
    }
    cache_.emplace_front(key, value);
    map_[key] = cache_.begin();
  }

 private:
  std::list<std::pair<int, int>> cache_;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
  int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
