#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

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
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    static ListNode *reverseAlternateK(ListNode *head, int k)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        int count = 0;

        while (curr != nullptr && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (head != nullptr)
        {
            head->next = curr;
        }

        count = 0;
        while (curr != nullptr && count < k - 1)
        {
            curr = curr->next;
            count++;
        }

        if (curr != nullptr)
        {
            curr->next = reverseAlternateK(curr->next, k);
        }

        return prev;
    }

    static ListNode *mergeLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (list1 && list2)
        {
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;

            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }

        if (list1)
            tail->next = list1;
        if (list2)
            tail->next = list2;

        return dummy.next;
    }
};

int main()
{
    int n, x, k;
    cin >> n;
    vector<int> values(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    cin >> x >> k;

    ListNode *head = LinkedList::createLinkedList(values);

    ListNode *divisibleHead = nullptr, *divisibleTail = nullptr;
    ListNode *nonDivisibleHead = nullptr, *nonDivisibleTail = nullptr;

    ListNode *temp = head;

    while (temp)
    {
        if (temp->val % x == 0)
        {
            if (!divisibleHead)
                divisibleHead = divisibleTail = temp;
            else
            {
                divisibleTail->next = temp;
                divisibleTail = temp;
            }
        }
        else
        {
            if (!nonDivisibleHead)
                nonDivisibleHead = nonDivisibleTail = temp;
            else
            {
                nonDivisibleTail->next = temp;
                nonDivisibleTail = temp;
            }
        }
        temp = temp->next;
    }

    if (divisibleTail)
        divisibleTail->next = nullptr;
    if (nonDivisibleTail)
        nonDivisibleTail->next = nullptr;

    divisibleHead = LinkedList::reverseAlternateK(divisibleHead, k);
    nonDivisibleHead = LinkedList::reverseAlternateK(nonDivisibleHead, k);

    ListNode *result = LinkedList::mergeLists(divisibleHead, nonDivisibleHead);

    LinkedList::printLinkedList(result);

    return 0;
}