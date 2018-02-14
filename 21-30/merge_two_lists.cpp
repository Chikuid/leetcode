#include <iostream>

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

int main() {
	ListNode *input1, *input2, *output;
	input1 = createList();
	input2 = createList();
	output = mergeTwoLists(input2, input1);
	printList(output, "output");
	return 0;
}