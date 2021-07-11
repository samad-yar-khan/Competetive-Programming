#include<iostream>
using namespace std;

template <typename T>

class Queue
{

    private :

    T* arr ;
    int capacity;
    int first_index ;
    int next_index ;
    int size ;


    public :

    Queue(){

        T* arr = new T[10];
        first_index=-1;
        next_index = 0;
        size = 0;
        capacity = 10 ;
    }

    int getSize(){
        return size;
    }


    void enque(T element){

        if()

    }





};
