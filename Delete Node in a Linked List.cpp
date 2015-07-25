class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node != NULL && node->next != NULL) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};
//redo
void delete(ListNode* node) {
  if(node->next) {
    ListNode* t = node->next;
    node->val = t->val;
    node->next = t->next;
    delete t;
  }
}

