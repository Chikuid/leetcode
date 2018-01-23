#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *sumSentinel = new ListNode(-1);
  ListNode *curr = sumSentinel;
  if (l1 == NULL && l2 == NULL) {
    return sumSentinel->next;
  }
  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;
  int c = 0;
  int a,b,v;

  while (l1 != NULL || l2 != NULL || c != 0) {

    if (l1 != NULL) {
      a = l1->val;
      l1 = l1->next;
    }
    else a = 0;

    if (l2 != NULL){
      b = l2->val;
      l2 = l2->next;
    }
    else b = 0;

    v = (a+b+c) %10;
    c = (a+b+c)/10;

    ListNode *temp = new ListNode(v);
    curr->next = temp;
    curr = curr->next;
  }
  return sumSentinel->next;
}

void printList(ListNode *head) {
  while(head != NULL) {
    std::cout << head->val << "->";
    head = head->next;
  }
  std::cout << "NULL" << '\n';
}

ListNode* createList(int N) {
  ListNode *head = NULL;
  if(N==0) {
    return head;
  }
  int val;
  for (int i = 0; i < N; i++) {
    cin>>val;
    ListNode *temp = new ListNode(val);
    temp->next = head;
    head = temp;
  }
  return head;
}

int main() {
  ListNode *l1, *l2;
  l1 = createList(1);
  l2 = createList(1);
  printList(l1);
  printList(l2);
  printList(addTwoNumbers(l1, l2));
  return 0;
}
