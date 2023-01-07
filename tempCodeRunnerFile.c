#include<stdio.h>

struct Node {
int value;
struct Node *next;
struct Node *prev;
};

struct Node * initialize_linked_list(int value) {
struct Node * first = (struct Node *) malloc(sizeof(struct Node));
first->value = value;
first->next = NULL;
first->prev = NULL;
return first;
}

struct Node * add(int value, struct Node * node) {
struct Node * to_be_added = (struct Node *) malloc(sizeof(struct Node));
to_be_added->value = value;
to_be_added->next = node->next;
to_be_added->prev = node;
if(node->next != NULL)
node->next->prev = to_be_added;
node->next = to_be_added;
return to_be_added;
}

void traverse_list(struct Node * first) {
while (first != NULL) {
printf("%d ", first->value);
first = first->next;
}
printf("\n");

}

struct Node * delete(struct Node * first, struct Node * node) {
struct Node * first_ = first;
if(node != NULL) {
if(node->prev != NULL)
node->prev->next = node->next;
else
first_ = first->next;
if(node->next != NULL)
node->next->prev = node->prev;
free(node);
}

return first_;
}

struct Node * find(struct Node * first, int value) {
while(first != NULL) {
if(first->value == value)
return first;
first = first->next;
}
return NULL;
}

int main() {
struct Node * myll = initialize_linked_list(50);
struct Node * temp = add(10, myll);
struct Node * temp2 = add(30, temp);
temp = add(90, temp2);
traverse_list(myll);
myll = delete(myll, find(myll, 50));
traverse_list(myll);

return 0;
}