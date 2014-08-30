#ifndef LLIST_H
#define LLIST_H
#include "Node.h"
#include <stdexcept>

using namespace std;

template <typename E>
class LList
{
private:
    Node<E> *head;
    Node<E> *tail;
    Node<E> *current;
    int size;

public:
    LList() {
        current = tail = head = new Node<E>();
        size = 0;
    }

    void append(E pElement) {
        tail->next = new Node<E>(pElement);
        tail = tail->next;
        size++;
    }

    void insert( E pElement){
        current->next = new Node <E> (pElement,current->next);
        if (current == tail){
            tail = tail->next;
        }
        size++;
    }


    E remove() throw (runtime_error){
        if (size == 0){
            throw runtime_error("The list is empty.");
        }
        if (current == tail){
            throw runtime_error("No hay elemento para borrar");
        }
        E result = current -> next -> element;
        Node<E> * temp = current -> next;
        current -> next = current -> next-> next;
        if (temp ==tail){
            tail = current;
        }
        delete temp;
        size --;
        return result;
        }

    void clear(){
        while (head->next != NULL){
            current = head->next;
            head->next = head ->next->next;
            delete current;
        }
        tail = current= head;
        size = 0;
    }
    E getElement() throw(runtime_error){
        if (size == 0){
            throw runtime_error("The list is empty");
        }
        if (current == tail){
            throw runtime_error("No element to get");
        }
        return  current-> next-> element;
    }
    void next(){
        if (current -> next != NULL){
            current = current -> next;
        }
    }

    void previous(){
    if (current != head){
        Node<E> * temp = head;
            while(temp -> next != current){
                temp = temp -> next;
            }
        current = temp;
    }
}

    void goToStart(){
        current = head;
    }

    void goToEnd() {
        current = tail;
    }

    void goToPos(int pPos) throw (runtime_error){
        if ((pPos < 0) || (pPos > size )){
            throw runtime_error("Index out of bounds");
        }
        else{
            int contador = 0;
            current = head;
                while (contador < pPos){
                    current = current->next;
                contador ++;
                }
        }
    }

    int getSize() {
        return size ;
    }

    int getPos(){
        int pos = 0;
        Node <E>*temp = head;
        while(temp != current){
            pos ++ ;
        temp = temp->next;
        }
    return pos;
    }
};

#endif // LLIST_H
