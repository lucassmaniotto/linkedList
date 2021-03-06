#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 40

struct _func{
    int id;
    char name[N];
    double salary;
    struct _func *next;
};
typedef struct _func Employee;

int emptyList(Employee *first){
    if(first == NULL)
        return 1;
    return 0;
}

//Adiciona um elemento antes do primeiro
Employee *addHead(Employee *first, Employee *new){
    if(emptyList(first))
        return new;    

    new->next = first;
    first = new;

    return first;
}

Employee *addTail(Employee *first, Employee *new){
    Employee *aux;

    if(emptyList(first))
        return new;
    for(aux = first; aux->next != NULL; aux = aux->next);
    /*
    aux = first;
    while(aux->next != NULL)
        aux = aux->next;
    */
    aux->next = new;

    return first;
}

Employee *addAfter(Employee *first, Employee *new, int id){
    Employee *aux;
    if(emptyList(first))
        return new;
    for(aux = first; aux != NULL; aux = aux->next){
        if(aux->id == id){
            new->next = aux->next;
            aux->next = new;
        }
    }
    return first;
}
/*Employee *addBefore(Employee *first, Employee *new, int id){

}
*/

Employee *createEmploye(int id, char name[], double salary){

    Employee *new = malloc(sizeof(Employee));
    new->id = id;
    snprintf(new->name, sizeof(new->name), "%s", name);
    strcpy(new->name, name);
    new->salary = salary;
    new->next = NULL;

    return new;
}

void printEmployee(Employee *first){
    Employee *aux;

    for(aux = first; aux != NULL; aux = aux->next)
        printf("%d %s %.2lf\n", aux->id, aux->name, aux->salary);
    printf("\n");
}

void printEmployeeReverse(Employee *first){
    if(first == NULL)
        return;
    printEmployeeReverse(first->next);
    printf("%d %s %.2lf\n", first->id, first->name, first->salary);
}


int main (){

    Employee *first = NULL, *aux,*f;

    first = addHead(first, createEmploye(1, "Teste 1", 2548.78));
    first = addHead(first, createEmploye(2, "Teste 2", 2548.78));
    first = addHead(first, createEmploye(3, "Teste 3", 2548.78));
    first = addHead(first, createEmploye(4, "Teste 4", 2548.78));
    first = addTail(first, createEmploye(0, "Teste 0", 2548.78));
    first = addAfter(first, (createEmploye(7, "Teste 0", 2548.78)), 3);

    printEmployee(first);
    printEmployeeReverse(first);

    return 0;
}