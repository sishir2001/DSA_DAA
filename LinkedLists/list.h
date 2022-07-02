// Forward declaration
using namespace std;
class List;
class Node {
    int data;
    Node *next;

 public:
    Node(int d) : data(d), next(NULL) {}  // new type of initialization
    ~Node() {
        if (this->next) {
            delete this->next;  // kind of a recursive call
        }
    }
    friend class List;
};

class List {
    Node *head, *tail;

 public:
    List() {
        this->head = NULL;
        this->tail = NULL;
    }
    List(int data) {
        this->head = new Node(data);
        this->tail = this->head;
    }

    ~List() {
        // destructor
        delete this->head;
        this->head = NULL;
    }

    Node *begin() { return this->head; }
    void set_begin(Node *head) { this->head = head; }
    Node *back() { return this->tail; }
    void set_back(Node *tail) { this->tail = tail; }

    void push_front(int data) {
        Node *n = new Node(data);
        if (!this->head) {
            // head and tail are null
            this->head = n;
            this->tail = n;
        } else {
            n->next = this->head;
            this->head = n;
        }
    }

    int search(int data) {
        // 0-indexing
        int idx = 0;
        Node *curr = this->head;
        while (curr) {
            if (data == curr->data)
                return idx;
            curr = curr->next;
            idx++;
        }
        return -1;
    }

    void push_back(int data) {
        Node *n = new Node(data);
        if (!this->head) {
            // head and tail are null
            this->head = n;
            this->tail = n;
        } else {
            this->tail->next = n;
            this->tail = n;
        }
    }

    void pop_front() {
        if (!this->head)
            return;
        else if (!this->head->next) {
            // only single node ,
            this->tail = NULL;
            delete this->head;
            this->head = NULL;
        } else {
            Node *temp = this->head;
            this->head = this->head->next;
            temp->next = NULL;
            delete temp;
            temp = NULL;
        }
    }
    void pop_back() {
        if (!this->head)
            return;
        else if (!this->head->next) {
            // single node
            this->tail = NULL;
            delete this->head;
            this->head = NULL;
        } else {
            // > 1 node
            // TODO : loop till the prev_last node
            Node *prev = NULL, *curr = this->head;
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }
            this->tail = prev;
            this->tail->next = NULL;
            delete curr;
        }
    }

    void insert(int data, int pos) {
        if (pos == 0) {
            this->push_front(data);
            return;
        }
        // 1->2->3->4
        Node *curr = this->head->next, *prev = this->head;
        int curr_pos = 1;
        Node *temp = new Node(data);
        while (curr) {
            if (curr_pos == pos) {
                temp->next = curr;
                prev->next = temp;
            }
            prev = curr;
            curr = curr->next;
            curr_pos++;
        }
        if (curr_pos == pos) {
            prev->next = temp;
        }
        return;
    }
    void remove(int pos) {
        if (pos == 0)
            this->pop_front();
        int curr_pos = 1;
        Node *curr = this->head->next, *prev = this->head;
        while (curr) {
            if (curr_pos == pos) {
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                curr = NULL;
                return;
            }
            prev = curr;
            curr = curr->next;
            curr_pos++;
        }
    }

    List *reverse_list(List *l) {
        // !T(N) = O(N)
        Node *curr = l->begin(), *rev_head = NULL, *rev_tail = NULL,
             *p = l->begin();
        List *r_l = new List();
        while (curr) {
            curr = curr->next;
            p->next = rev_head;
            if (!rev_head) {
                rev_tail = p;
            }
            rev_head = p;
            p = curr;
        }
        r_l->set_begin(rev_head);
        r_l->set_back(rev_tail);
        return r_l;
    }

    void print_list() {
        Node *curr = this->head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
};
