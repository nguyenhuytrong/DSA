## Linked List 
Mỗi node có data + next (chỉ ra node tiếp theo)

Node đầu tiên gọi là `head`

Node cuối cùng có `next = nullptr` (không còn toa nào nối tiếp)

Ta sẽ dùng con trỏ `*` để khởi tạo một Linked List mới, với `head` trỏ vào `10` 
```
Node* head = new Node(10);      
head->next = new Node(20);     
head->next->next = new Node(30);

head → [10 | next] → [20 | next] → [30 | next] → nullptr
```

**Các thao tác cơ bản**

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
**Lưu ý**

- Luôn kiểm tra `nullptr` trước khi truy cập. Nếu `curr == nullptr` mà vẫn `curr->next` → `segmentation fault`

``` 
if (curr != nullptr) curr = curr->next;
```
- Dummy Node 

Dummy node là node giả đứng trước `head`, khai báo `Node* dummy = new Node(-1)`

Sau khi thao tác, kết quả thực sự bắt đầu từ `dummy->next`

- Thêm/xóa node cần cẩn thận thứ tự thao tác
Nếu thay đổi next sai → mất liên kết cả danh sách còn lại

Luôn lưu next tạm thời trước khi sửa: `Node* nextNode = curr->next`



## Problems
- Prob1: [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)
- Prob2: [203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/description/)
- Prob3: [876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)
- Prob4: [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/)
