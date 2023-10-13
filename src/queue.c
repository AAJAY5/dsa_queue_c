#include "queue.h"

#ifdef DEBUG_QUEUE
    #include <stdio.h>
    #define DEBUG(fmt, ...) printf("[%s][%s:%u]" fmt, __func__, __FILE__, __LINE__##__VA_ARGS__)
    #else
    #define DEBUG(fmt, ...) ((void)0)
#endif

queue_t *queue_create(size_t e_size, size_t e_count) {
    if ((e_size <= 0) || (e_count <= 0)) {
        DEBUG("Invalid size or count\r\n");
        return NULL;
    }

    void *mem = calloc(e_count, e_size);
    if (!mem) {
        DEBUG("Unable to calloc mem\r\n");
        return NULL;
    }

    queue_t *queue = calloc(1, sizeof(queue_t));
    if (!queue) {
        DEBUG("Unable to calloc queue\r\n");
        return NULL;
    }

    queue->count = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->e_count = e_count;
    queue->e_size = e_size;
    queue->mem = mem;

    return queue;
}

bool queue_enque(queue_t *queue, void *ele) {
    if (!queue) {
        DEBUG("Invalid Queue\r\n");
        return false;
    }

    if (!ele) {
        DEBUG("Invalid ele\r\n");
        return false;
    }

    if (queue_is_full(queue)) {
        DEBUG("Queue Full\r\n");
        return false;
    }

    memcpy((queue->mem + (queue->head * queue->e_size)), ele, queue->e_size);
    queue->head = ((queue->head + 1) % queue->e_count);
    queue->count++;

    return true;
}

bool queue_deque(queue_t *queue, void *ele) {
    if (!queue) {
        DEBUG("Invalid Queue\r\n");
        return false;
    }

    if (!ele) {
        DEBUG("Invalid ele\r\n");
        return false;
    }

    if (queue_is_empty(queue)) {
        DEBUG("Queue Empty\r\n");
        return false;
    }

    memcpy(ele, (queue->mem + (queue->tail * queue->e_size)), queue->e_size);
    queue->tail = ((queue->tail + 1) % queue->e_count);
    queue->count--;

    return true;
}

bool queue_peek(queue_t *queue, void *ele) {
    if (!queue) {
        DEBUG("Invalid Queue\r\n");
        return false;
    }

    if (!ele) {
        DEBUG("Invalid ele\r\n");
        return false;
    }

    if (queue_is_empty(queue)) {
        DEBUG("Queue Empty\r\n");
        return false;
    }

    memcpy(ele, (queue->mem + (queue->tail * queue->e_size)), queue->e_size);
    return true;
}

bool queue_is_empty(queue_t *queue) {
    if (!queue) {
        DEBUG("Invalid queue\r\n");
        return false;
    }

    return (queue->count == 0);
}

bool queue_is_full(queue_t *queue) {
    if (!queue) {
        DEBUG("Invalid queue\r\n");
        return false;
    }

    return (queue->count == queue->e_count);
}

size_t queue_available(queue_t *queue) {
    if (!queue) {
        DEBUG("Invalid queue\r\n");
        return 0;
    }

    return queue->count;
}

size_t queue_size(queue_t *queue) {
    if (!queue) {
        DEBUG("Invalid queue\r\n");
        return 0;
    }

    return queue->e_count;
}

void queue_delete(queue_t **queue) {
    if (!(*queue)) {
        DEBUG("Invalid queue\r\n");
        return;
    }

    if (!(*queue)->mem) {
        DEBUG("Invalid mem\r\n");
        return;
    }

    free((*queue)->mem);
    (*queue)->mem = NULL;

    free((*queue));
    *queue = NULL;
}
