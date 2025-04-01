#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    // Constructors
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;

        ListNode *node = head;
        for (int i = 0; i < k; ++i)
        {
            if (node == NULL)
                return head;
            node = node->next;
        }

        ListNode *next = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int count = 0;

        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};

// Helper function to create a linked list from an array
class LinkedList
{
public:
    static ListNode *createLinkedList(const vector<int> &arr)
    {
        if (arr.empty())
            return nullptr;

        ListNode *head = new ListNode(arr[0]);
        ListNode *tail = head;

        for (size_t i = 1; i < arr.size(); ++i)
        {
            tail->next = new ListNode(arr[i]);
            tail = tail->next;
        }

        return head;
    }

    static void printLinkedList(ListNode *head)
    {
        while (head != nullptr)
        {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    int k = 3;

    ListNode *head = LinkedList::createLinkedList(values);
    cout << "Original List: ";
    LinkedList::printLinkedList(head);

    Solution sol;
    head = sol.reverseKGroup(head, k);

    cout << "Reversed in Groups of " << k << ": ";
    LinkedList::printLinkedList(head);

    return 0;
}