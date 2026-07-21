/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Reverse a linked list
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverse(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    // Return the kth node starting from temp
    ListNode* getKthNode(ListNode* temp, int k) {
        k--;

        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp != NULL) {

            ListNode* kthNode = getKthNode(temp, k);

            if (kthNode == NULL) {
                if (prevNode != NULL)
                    prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverse(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prevNode->next = newHead;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};