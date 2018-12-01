// Remove duplicates from an unsorted linked list
class Node {
    int data;
    Node next = null;

    public Node(int data) {
        this.data = data;
    }

    Node appendToTail(int data) {
        Node newNode = new Node(data);
        Node curr = this;
        
        
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.next = newNode;
        return this;
    }

    Node appendToHead(int data) {
        Node newNode = new Node(data);
        newNode.next = this;
        return newNode;
    }
    
    void displayList() {
        Node curr = this;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
        System.out.println();

    }

    Node deleteNode(int data) {
        Node curr = this;

        if (curr.data == data) {
            return curr.next;
        }

        while (curr != null) {
            if (curr.next.data == data) {
                curr.next = curr.next.next;
                return this;
            }
            curr = curr.next;
        }

        return this;
    }
}

class LinkedList {
    Node head;

    public LinkedList(int data) {
        head = new Node(data);
    }

    void appendToHead(int data) {
        head = head.appendToHead(data);
    }

    void appendToTail(int data) {
        head = head.appendToTail(data);
    }

    void displayList() {
        if (head == null) {
            System.out.println("No elements to display!");
            return;
        }
        head.displayList();
    }

    void deleteNode(int data) {
        head = head.deleteNode(data);
    }

    void deleteDups() {
        Node back = head;
        if (back.next == null) {
            return;
        }
        while (back != null) {
            Node runner = back;
            while (runner != null) {
                if (runner.next !=null && (runner.next.data == back.data)) {
                    runner.next = runner.next.next;
                    continue;
                }
                runner = runner.next;
            }
            back = back.next;
        }
    }


}

class RemoveDups {
    public static void main(String args[]) {
        LinkedList ll = new LinkedList(1);
        ll.appendToHead(3);
        ll.appendToHead(2);
        ll.appendToHead(2);
        ll.appendToHead(3);
        ll.appendToHead(2);
        ll.appendToHead(2);
        ll.appendToHead(3);
        ll.appendToHead(1);
        ll.appendToHead(2);
        ll.appendToHead(1);
        ll.appendToHead(2);
        ll.appendToHead(2);
        ll.appendToHead(1);
        ll.appendToHead(2);
        ll.appendToHead(1);
        ll.appendToHead(2);
        ll.appendToHead(2);

        ll.displayList();

        ll.deleteDups();
        ll.displayList();


        


    }
}