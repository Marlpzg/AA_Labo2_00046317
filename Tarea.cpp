#include <cstdlib>
#include <iostream>

using namespace std;

//Estructura del nodo.
struct Node{
    int value;
    Node* next;
};

//Clase de la lista simple.
class SimpleList{
    private:
        Node* start;    //Puntero al inicio de la lista.
    public:
        //Constructor
        SimpleList(){
            start = nullptr;
        }

        //Función que crea un nodo nuevo.
        Node* createNode(int data){
            Node* n = new Node;
            n->value = data;
            n->next = nullptr;
            return n;
        }

        //Función que agrega un nodo nuevo alf inal de la lista.
        void add(int data){
            Node* n = createNode(data), *temp;
            if(!start){
                start = n;
            }else{
                for(temp=start; temp->next; temp=temp->next);
                temp->next = n;
            }
        }

        //Función que muestra el contenido de la lista.
        void show(){
            Node* temp = start;
            if(!start){
                cout << "La lista no posee elementos" << endl;
            }else{
                while(temp){
                    cout << temp->value << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        //Función que obtiene el tamaño de la lista.
        int size(){
            Node* temp = start;
            int count = 0;
            if(!start){
                return count;
            }

            while(temp){
                temp = temp->next;
                count++;
            }
            return count;
        }

        //Función que calcula el promedio de la lista.
        double avg(){
            int size = 0;
            int sum = 0;
            Node* temp = start;

            while(temp){
                sum += temp->value;
                size++;
                temp = temp->next;
            }

            if(size == 0){
                return 0.0;
            }

            return (sum*1.0)/(size*1.0);
        }

        //Función que devuelve una nueva lista con los elementos que están arriba del promedio.
        SimpleList getOverAvg(){
            SimpleList list;
            double avg = this-> avg();

            if(this->size() == 0){
                return list;
            }

            Node* temp = start;

            while(temp){
                if(temp->value > avg){
                    list.add(temp->value);
                }
                temp = temp->next;
            }

            return list;

        }
};

int main(){
    //Llenado de la lista principal.
    SimpleList lista;
    lista.add(1);
    lista.add(2);
    lista.add(3);
    lista.add(4);
    lista.add(5);
    lista.add(6);

    //Llenado de la lista con los elementos arriba del promedio. 
    SimpleList newList = lista.getOverAvg();

    //Print de las listas.
    lista.show();
    newList.show();

    return 0;
}