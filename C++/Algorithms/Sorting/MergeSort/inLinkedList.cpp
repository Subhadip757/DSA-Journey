#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the middle node
ListNode *getMiddle(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next; // Move fast one step ahead

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
ListNode *merge(ListNode *left, ListNode *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    ListNode *result = nullptr;
    if (left->val <= right->val)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Merge Sort function for linked list
ListNode *mergeSort(ListNode *head)
{
    if (!head || !head->next)
        return head; // Base case: single node or empty list

    // Step 1: Split the list into two halves
    ListNode *middle = getMiddle(head);
    ListNode *secondHalf = middle->next;
    middle->next = nullptr; // Break the list into two parts

    // Step 2: Recursively sort both halves
    ListNode *left = mergeSort(head);
    ListNode *right = mergeSort(secondHalf);

    // Step 3: Merge the sorted halves
    return merge(left, right);
}

// Function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main()
{
    // Example: Creating an unsorted linked list: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    // Sorting the linked list
    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}