#include <iostream>
#include <string>
using namespace std;

class Login
{
private:
    string username = "Admin";
    int password = 12345;

public:
    int In = 0;
    void tryLogin(string username, int password)
    {
        if (username == "Admin" && password == 12345)
        {
            In = 1;
        }
        else
        {
            cout << "Incorrect Password" << endl;
            In = 0;
        }
    };
};

class Node
{
public:
    int key;
    string data;
    Node *next;
    Node()
    {
        key = 0;
        data = "";
        next = NULL;
    }
    Node(int k, string d)
    {
        key = k;
        data = d;
    }
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList()
    {
        head = NULL;
    }
    Node *nodeExists(int k)
    {

        Node *temp = NULL;
        Node *ptr = head;

        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;

            } while (ptr != head);
            return temp;
        }
    }
    void appendNode(Node *new_node)
    {
        if (nodeExists(new_node->key) != NULL)
        {
            cout << "Todo  Already exists with sr number of : " << new_node->key << ". Try updating the Todo List with different sr number" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = new_node;
                new_node->next = head;
                cout << "Todo List Updated" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
                new_node->next = head;
                cout << "Todo List Updated" << endl;
            }
        }
    }
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Todo exist with sr number of : " << k << endl;
        }
        else
        {

            if (ptr == head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    cout << "Last Todod deleted ";
                }
                else
                {
                    Node *ptr1 = head;
                    while (ptr1->next != head)
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next;
                    head = head->next;
                    cout << "Todo with sr number" << k << " deleted";
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }

                prevptr->next = temp->next;
                cout << "Node UNLINKED with keys value : " << k << endl;
            }
        }
    }
    void printList()
    {
        if (head == NULL)
        {
            cout << endl
                 << "No Todos left";
        }
        else
        {
            cout << endl;
            cout << "The remaining Todos are : " << endl;
            Node *temp = head;
            do
            {
                cout << temp->key << ":" << temp->data;
                temp = temp->next;
                cout << endl;
            } while (temp != head);
        }
    }
};

int main()
{
    Login l;
    CircularLinkedList c;
    string data1, username;
    int option, key1, password;
    do
    {
        cout << endl
             << " __________________________________________" << endl
             << "|##########################################|" << endl
             << "|#                                        #|" << endl
             << "|#                                        #|" << endl
             << "|#                                        #|" << endl
             << "|#                  TODO                  #|" << endl
             << "|#       __________________________       #|" << endl
             << "|#                                        #|" << endl
             << "|#                0.Exit                  #|" << endl
             << "|#                1.Login                 #|" << endl
             << "|#                                        #|" << endl
             << "|#                                        #|" << endl
             << "|# _______________________________________#|" << endl
             << "|##########################################|" << endl;
        cin >> option;
        Node *n1 = new Node();
        switch (option)
        {
        case 1:
            cout << endl
                 << endl
                 << "Enter the username :";
            cin >> username;
            cout << endl
                 << "Enter the password :";
            cin >> password;
            l.tryLogin(username, password);
            if (l.In == 1)
            {
                do
                {
                    cout << endl
                         << endl
                         << " __________________________________________" << endl
                         << "|##########################################|" << endl
                         << "|#                                        #|" << endl
                         << "|#                                        #|" << endl
                         << "|#                                        #|" << endl
                         << "|#        Select appropriate option       #|" << endl
                         << "|#                                        #|" << endl
                         << "|#                                        #|" << endl
                         << "|#               1.New Todo               #|" << endl
                         << "|#              2.View Todo               #|" << endl
                         << "|#              3.Delete Todo             #|" << endl
                         << "|#                                        #|" << endl
                         << "|#                                        #|" << endl
                         << "|# _______________________________________#|" << endl
                         << "|##########################################|" << endl;
                    cin >> option;
                    Node *n1 = new Node();
                    switch (option)
                    {
                    case 1:
                        cout << endl
                             << endl
                             << "____________________________________" << endl
                             << "--------------New Todo--------------" << endl
                             << endl;
                        cout << "Enter sr.no :";
                        cin >> key1;
                        cout << endl
                             << "Enter the ToDo :";
                        cin.ignore();
                        getline(cin, data1);
                        n1->key = key1;
                        n1->data = data1;
                        cout << n1->key << endl;
                        cout << n1->data << endl;
                        c.appendNode(n1);
                        break;
                    case 2:
                        cout << endl
                             << endl
                             << "____________________________________" << endl
                             << "--------------View Todo------------" << endl
                             << endl;
                        c.printList();
                        break;
                    case 3:
                        cout << endl
                             << endl
                             << "____________________________________" << endl
                             << "--------------Delete Todo-----------" << endl
                             << endl;
                        cout << "Enter the sr no of the Todo which you want to delete :";
                        cin >> key1;
                        c.deleteNodeByKey(key1);
                        break;
                    default:
                        cout << endl
                             << "Enter proper option number" << endl;
                    }
                } while (option != 0);
            }
            else
            {
                cout << endl
                     << "Enter valid password";
            }
        default:
            cout << endl
                 << "Enter valid option";
        }

    } while (option != 0);
}