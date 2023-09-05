/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

private:
    void insertNode(Node* &head, Node* &tail, int d)
    {
        Node* newNode = new Node(d);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return ;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }

public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        //clone list using next pointer
        while(temp != NULL)
        {
            insertNode(cloneHead, cloneTail, temp -> val);
            temp = temp -> next;
        }

        // cloneNodes add between original list
        temp = head;
        Node* cloneNode = cloneHead;
        while(temp != NULL && cloneNode != NULL)
        {
            Node* next = temp -> next;
            temp -> next = cloneNode; 
            temp = next;

            next = cloneNode -> next;
            cloneNode -> next = temp;
            cloneNode = next;
        }

        //clone random pointer
        temp = head;
        while(temp != NULL)
        {
            if(temp -> next != NULL)
            {
                temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
            }
            temp = temp -> next -> next;
        }

        // revert back to normal
        temp = head;
        cloneNode = cloneHead;
        while(temp != NULL && cloneNode != NULL)
        {
            temp -> next = cloneNode -> next;
            temp = temp -> next;
            if(temp!=NULL)
            cloneNode -> next = temp -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
};
