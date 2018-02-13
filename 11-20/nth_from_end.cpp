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

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *seeker = head;
	ListNode *target = head;
	if (head == NULL) return head;
	if (head-> next == NULL) {
		ListNode* temp = NULL;
		return temp;
	}
	while(n--) {
		seeker = seeker->next;
	}

	if (seeker == NULL) return head->next;

	while(seeker->next != NULL) {
		seeker = seeker->next;
		target = target->next;
	}

	target->next = target->next->next;
	return head;
}

int main() {
	ListNode* input, *output;
	cout<<"Enter the list below:**************************\n";
	input = createList();
	int n;
	cout<<"Enter the position: ";
	cin>>n;
	output = removeNthFromEnd(input, n);
	printList(input, "input");
	printList(output, "output");
	return 0;
}