#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


void printList(ListNode* head, string name) {
	cout<<"List Name :"<<name<<'\n';
	while(head != NULL) {
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"NULL\n";
}

ListNode* createList() {
	int n;
	
	cout<<"Enter size: ";
	cin>>n;
	cout<<"Now enter nums: \n";
	
	ListNode *sentinel, *curr;
	sentinel = new ListNode(0);
	curr = sentinel;
	
	while(n--) {
		int val;
		cin>>val;
		ListNode* temp = new ListNode(val);
		curr->next = temp;
		curr = curr->next;
	}
	return sentinel->next;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *sentinel, *curr;
	sentinel = new ListNode(0);
	curr = sentinel;
	while(l1 != NULL && l2 != NULL) {
		if (l1->val < l2->val)
		{
			curr->next = l1;
			curr = curr->next;
			l1 = l1->next;
		}
		else 
		{
			curr->next = l2;
			curr = curr->next;
			l2 = l2->next;
		}
	}
	if (l1 != NULL) {
		curr->next = l1;
	}
	else if (l2 != NULL) {
		curr->next = l2;
	}

	return sentinel->next;
}


ListNode *mergeKLists(vector<ListNode*> &lists){
	int len = lists.size();
	if (len == 0) return NULL;
	if (len == 1) return lists[0];

	for (int i = 1; i < len; ++i)
	{
		lists[i] = mergeTwoLists(lists[i-1], lists[i]);
	}
	return lists[len-1];
}


int main() {
	int n;
	cin>>n;
	vector <ListNode*> lists;

	for (int i = 0; i < n; ++i)
	{
		lists.push_back(createList());
	}

	ListNode *ans = mergeKLists(lists);

	printList(ans, "ans");
}