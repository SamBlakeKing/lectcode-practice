#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct ListNodeManager{
	ListNode *begin;
	ListNode *end;
	ListNodeManager(ListNode *b, ListNode *e) :begin(b), end(e){}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (NULL == head)
			return NULL;
		ListNode *temp = head;
		while (temp->next)
			temp = temp->next;
		ListNodeManager res = subSort(ListNodeManager(head, temp));

		return res.begin;
	}

	ListNodeManager subSort(ListNodeManager manager){
		ListNode *b = manager.begin, *e = manager.end;

		if (b == e)
			return manager;

		ListNode *current = b,*current_end = b, *list_less = NULL, *list_more = NULL, *begin = NULL, *end = NULL, *temp;
		b = b->next;
		while (b){
			if (current->val == b->val){
				current_end->next = b;
				current_end = current_end->next;
				b = b->next;
			}
			else if (current->val > b->val){
				if (NULL == list_less)
					begin = b;
				temp = b->next;
				b->next = list_less;
				list_less = b;
				b = temp;
			}
			else{
				if (NULL == list_more)
					end = b;
				temp = b->next;
				b->next = list_more;
				list_more = b;
				b = temp;
			}
		}
		current_end->next = NULL;
		ListNodeManager temp1 = subSort(ListNodeManager(list_less, begin));
		ListNodeManager temp2 = subSort(ListNodeManager(list_more, end));
		if (NULL == temp1.begin){
			begin = current;
		}
		else{
			begin = temp1.begin;
			temp1.end->next = current;
		}
		current_end->next = temp2.begin;
		if (NULL == temp2.begin)
			end = current_end;
		else
			end = temp2.end;

		return ListNodeManager(begin, end);
	}
};

int main(){
	Solution a;
	ListNode *head = NULL, *temp;
	int i;

	for (i = 0; i < 10; i++){
		temp = new ListNode(i);
		temp->next = head;
		head = temp;
	}
	temp = new ListNode(0);
	temp->next = head;
	head = temp;
	temp = new ListNode(9);
	temp->next = head;
	head = temp;

	head = a.sortList(head);
	temp = head;

	while (head){
		temp = head;
		head = head->next;

		cout << temp->val << endl;
		delete temp;
	}

	cin >> i;

	return 0;
}
