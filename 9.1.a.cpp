#include <iostream>
#include <vector>
#include <string>


class LinkedNode {
public:
    int value;
    LinkedNode* next;

    LinkedNode(int val, LinkedNode* nxt = nullptr) : value(val), next(nxt) {}
};

class LinkedList {
private:
    LinkedNode* head;
    int length;

public:
    LinkedList() : head(nullptr), length(0) {}

    ~LinkedList() {
        clear();
    }

    void clear() {
        LinkedNode* current = head;
        while (current != nullptr) {
            LinkedNode* temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
        length = 0;
    }

    int getLength() const {
        return length;
    }

    int getValueAtIndex(int index) {
        if (index <= 0 || index > length) {
            throw std::out_of_range("Invalid index");
        }

        LinkedNode* current = head;
        while (index > 1) {
            current = current->next;
            index--;
        }
        return current->value;
    }

    void addToFront(int value) {
        head = new LinkedNode(value, head);
        length++;
    }

    void insertAtIndex(int index, int value) {
        if (head == nullptr || index == 0) {
            addToFront(value);
        }
        else {
            LinkedNode* current = head;
            while (current->next != nullptr && index > 1) {
                current = current->next;
                index--;
            }
            current->next = new LinkedNode(value, current->next);
            length++;
        }
    }

    void removeAtIndex(int index = 1) {
        if (index == 1 || head->next == nullptr) {
            LinkedNode* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            LinkedNode* current = head;
            while (current->next->next != nullptr && index > 2) {
                current = current->next;
                index--;
            }
            LinkedNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        length--;
    }
};

int main() {
    int n;
    std::cin >> n;

    LinkedList link;
    std::vector<std::string> answer;

    for (int i = 0; i < n; ++i) {
        int queryType;
        std::cin >> queryType;

        if (queryType == 1) {
            int x, y;
            std::cin >> x >> y;
            link.insertAtIndex(x, y);
        }
        else if (queryType == 2) {
            int x;
            std::cin >> x;
            try {
                answer.push_back(std::to_string(link.getValueAtIndex(x)));
            }
            catch (const std::exception& e) {
                std::cerr << "Exception caught: " << e.what() << std::endl;
            }
        }
        else if (queryType == 3) {
            int x;
            std::cin >> x;
            link.removeAtIndex(x);
        }
    }

    for (const auto& ans : answer) {
        std::cout << ans << "\n";
    }

    return 0;
}