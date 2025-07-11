## Linked list 
- Khởi tạo node trong linked list (Define)
```
class Node {
    int data; 
    Node next;
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}
```
- Duyệt tìm kiếm có tồn tại data (Traverse / Search) 
```
bool search(int data) {
    Node curr = head; 
    while (curr != null) {
        if(curr.data == data) return true;
    }
    return false;
}
```

