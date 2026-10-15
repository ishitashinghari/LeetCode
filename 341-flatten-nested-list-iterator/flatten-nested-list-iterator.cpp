/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> v;
    vector<int>::iterator i;

    void flat(vector<NestedInteger> &nestedList){
        for(NestedInteger& j:nestedList){
            if(j.isInteger())
            v.push_back(j.getInteger());
            else
            flat(j.getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        flat(nestedList);
        i=v.begin();
    }
    
    int next() {
        return *i++;
    }
    
    bool hasNext() {
        return i!=v.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */