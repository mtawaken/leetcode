/*************************************************************************
    > File Name: work2.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20171224 110102
 ************************************************************************/


/*
 * METHOD1: map dedup extension: bucket hash
 * METHOD2: keep slide window, use BST/sort+binary serach to reduce time complex
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * BST template
 */
struct Node {
public:
    long long v;
    Node* l;
    Node* r;
    Node* p;
    Node(long _v) : v(_v), l(NULL), r(NULL), p(NULL){}
};

class BST {
public:
    BST() : head(NULL) {}
    void insert(long long v);
    void remove(long long v);
    bool find(long long floor, long long ceil);
private:
    Node* head;
    void transplant(Node* orig, Node* dest);
};

void BST::insert(long long v)
{
    Node* tmp = new Node(v);
    Node* parent = NULL;
    Node* cur = head;
    while (cur != NULL) {
        parent = cur;
        if (v <= cur->v) {
            cur = cur->l;
        } else {
            cur = cur->r;
        } } tmp->p = parent; if (parent == NULL) {
        head = tmp;
        return;
    }
    if (v <= parent->v) {
        parent->l = tmp;
    } else {
        parent->r = tmp;
    }
}

void BST::transplant(Node* orig, Node* dest)
{
    if (orig->p == NULL) {
        head = dest;
    } else if (orig->p->l == orig) {
        orig->p->l = dest;
    } else {
        orig->p->r = dest;
    }
    if (dest) {
        dest->p = orig->p;
    }
}

void BST::remove(long long v) 
{
    Node* parent = NULL;
    Node* cur = head;
    while (cur && cur->v != v) {
        parent = cur;
        if (v <= cur->v) {
            cur = cur->l;
        } else {
            cur = cur->r;
        }
    }
    if (!cur) {
        // Not found
        return;
    }
    /*
     * REMOVE NODE: 
     * 1. do transplant directly if node only has one child.
     * 2. use successor to replace node if has two children.
     */
    if (cur->l == NULL) {
        transplant(cur, cur->r);    
    } else if (cur->r == NULL) {
        transplant(cur, cur->l);
    } else {
        Node* succ = cur->r;
        if (succ->l != NULL) {
            while (succ->l != NULL) {
                succ = succ->l;
            }
            transplant(succ, succ->r);
            succ->r = cur->r;
            cur->r->p = succ;
        }
        transplant(cur, succ);
        succ->l = cur->l;
        cur->l->p = succ;
    }
    delete cur;
}

bool BST::find(long long floor, long long ceil)
{
    long s = min(floor, ceil);
    long e = max(floor, ceil);
    Node* cur = head;
    while (cur) {
        if (cur->v > e) {
            cur = cur->l;
        } else if (cur->v < s) {
            cur = cur->r;
        } else {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 || t < 0) {
            return false;
        }
        BST bst;
        long window = 0;
        for (long i = 0; i < nums.size(); ++i) {
            if (window == k + 1) {
                bst.remove(nums[i - k - 1]);
                window--;
            }
            /*
             * Way to avoid overflow/underflow:
             * 1. higher metric
             * 2. always bigger - smaller
             */
            long long s = (long long)nums[i] - t;
            long long e = (long long)nums[i] + t;
            if (bst.find(s, e)) {
                return true;
            }
            bst.insert(nums[i]);
            window++;
        }
        return false;
    }
};

int main() {
     vector<int> a {-1, 2147483647};
     Solution s;
     cout << s.containsNearbyAlmostDuplicate(a, 1, 2147483647);
}
