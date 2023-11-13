'''
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
 

Constraints:

-231 <= val <= 231 - 1
At most 2 * 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.
'''
import random

class RandomizedSet:

    def __init__(self):
        self.data_hash = {}
        self.data = []

    def insert(self, val: int) -> bool:
        if val in self.data_hash:
            return False

        # add the value and list index to the hash
        self.data_hash[val] = len(self.data)
        # add the data to the list
        self.data.append(val)

        return True
        
    def remove(self, val: int) -> bool:
        if val not in self.data_hash:
            return False
        
        # Swap the last element with the element to be removed
        last_element = self.data[-1]
        idx_to_remove = self.data_hash[val]

        self.data[idx_to_remove] = last_element
        self.data_hash[last_element] = idx_to_remove

        self.data[-1] = val

        # Remove the last element in the list and hash
        self.data.pop()
        self.data_hash.pop(val)

        return True

    def getRandom(self) -> int:
        return random.choice(self.data)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

if __name__ == "__main__":
    print("380_InsertDeleteGetRandom_O(1).py")
    print("\nCase 1")
    test_set = RandomizedSet()
    a1 = test_set.insert(1)
    a2 = test_set.remove(2)
    a3 = test_set.insert(2)
    a4 = test_set.getRandom()
    a5 = test_set.remove(1)
    a6 = test_set.insert(2)
    a7 = test_set.getRandom()
    res = [a1, a2, a3, a4, a5, a6, a7]
    ans = [True, False, True, 1, True, False, 2]
    print(f"result is {res}, check: {res==ans}")