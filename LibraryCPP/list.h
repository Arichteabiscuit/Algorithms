#ifndef LIST_H
#define LIST_H

struct ListItem {
    int data;
    ListItem* next;
    ListItem* prev;
};

struct List {
    ListItem* head;
    ListItem* tail;
};

// ������� ����� ������
List* list_create();

// ������� ������
void list_delete(List* list);

// ��������� ������� � ������ ������
void list_insert(List* list, int data);

// ��������� ������� ����� ���������� ����
void list_insert_after(List* list, ListItem* item, int data);

// ������� ������ ������� ������
void list_erase_first(List* list);

// ���������� ������ ������� ������
ListItem* list_first(const List* list);

// ���������� ������ �� �������� ������
int list_item_data(const ListItem* item);

// ���������� ��������� ������� ������
ListItem* list_item_next(const ListItem* item);

#endif // LIST_H