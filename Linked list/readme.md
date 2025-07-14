## Linked list 
- Khởi tạo node trong linked list (Define)
```
class Node {
public:
    int data; 
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
```
- Duyệt tìm kiếm có tồn tại data (Traverse / Search) 
```
bool search(int data) {
    Node* curr = head; 
    while (curr != nullptr) {
        if(curr->data == data) return true;
        curr = curr->next;
    }
    return false;
};
```
- Chèn node lên trên đầu (Insert at head)
```
void InsertAtHead (int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
```
- Chèn node vào cuối (Insert at tail) 
```
void InsertAtTail (int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
}
``` 
- Chèn node vào vị trí bất kì (Insert at any position)
```
void InsertAtPosition (int index, int data){
    if (index == 0) {
        InsertAtHead(data);
        return;
    }
    Node* newNode = new Node(data);
    Node* curr = head;
    for (int i=0; i < index - 1; i++) {
        if (curr != nullptr) curr = curr->next;
        else break;
    }
    if (curr == nullptr) return;
    newNode->next = curr->next;
    curr->next = newNode;
}
```
- Xóa node ở vị trí bất kì (Delete node)
```
void DeleteAtPosition (int index) {
    if (head == nullptr) return;

    if (index == 0) {
        head = head->next;
        return;
    }

    Node* curr = head;
    for (int i=0; i < index-1; i++) {
        if (curr != nullptr) curr = curr->next;
        else break;
    }
    if (curr == nullptr || curr->next == nullptr) return;
    curr->next = curr->next->next;
}
```
## Problems
- Prob1: [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)
- Prob2: [203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/description/)
- Prob3: [876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)
