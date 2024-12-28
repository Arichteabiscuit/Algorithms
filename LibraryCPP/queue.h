#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

struct Queue {
    List* list;
};

// ������� ����� �������
Queue* queue_create();

// ������� �������
void queue_delete(Queue* queue);

// ��������� ������� � ����� �������
void queue_insert(Queue* queue, int data);

// ���������� ������ ������� �������
int queue_get(const Queue* queue);

// ������� ������ ������� �������
void queue_remove(Queue* queue);

// ���������, ����� �� �������
bool queue_empty(const Queue* queue);

#endif // QUEUE_H
