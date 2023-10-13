#include <assert.h>
#include <stdio.h>

// Include the header file containing the functions to be tested
#include "../src/queue.h"

void test_queue_create() {
    // Test queue creation with valid arguments
    queue_t* queue = queue_create(sizeof(int), 5);
    assert(queue != NULL);
    assert((queue_size(queue) == 5));
    assert((queue_available(queue) == 0));
    assert(queue->e_size == sizeof(int));
    assert(queue->head == 0);
    assert(queue->tail == 0);
    assert(queue->mem != NULL);
    queue_delete(&queue);

    // Test queue creation with zero element count
    queue = queue_create(sizeof(int), 0);
    assert(queue == NULL);

    // Test queue creation with zero element size
    queue = queue_create(0, 5);
    assert(queue == NULL);
}

void test_queue_enque() {
    // Create a queue
    queue_t* queue = queue_create(sizeof(int), 5);
    assert(queue != NULL);

    // Test enqueing elements
    int ele = 10, read = 0;
    assert(queue_enque(queue, &ele) == true);
    assert(queue_available(queue) == 1);
    assert(queue_peek(queue, &read) == true);
    assert(read == ele);

    // Test enqueing an element when the queue is full
    ele = 20;
    assert(queue_enque(queue, &ele) == true);
    ele = 30;
    assert(queue_enque(queue, &ele) == true);
    ele = 40;
    assert(queue_enque(queue, &ele) == true);
    ele = 50;
    assert(queue_enque(queue, &ele) == true);
    assert(queue_enque(queue, &ele) == false);  // Queue should be full

    queue_delete(&queue);
}

void test_queue_deque() {
    // Create a queue and enqueue elements
    queue_t* queue = queue_create(sizeof(int), 5);
    int ele = 10;
    queue_enque(queue, &ele);
    ele = 20;
    queue_enque(queue, &ele);
    ele = 30;
    queue_enque(queue, &ele);

    // Test dequeing elements
    int dequeued;
    assert(queue_peek(queue, &dequeued) == true);

    assert(queue_deque(queue, &dequeued) == true);
    assert(dequeued == 10);
    assert(queue_available(queue) == 2);

    assert(queue_deque(queue, &dequeued) == true);
    assert(dequeued == 20);
    assert(queue_available(queue) == 1);

    assert(queue_deque(queue, &dequeued) == true);
    assert(dequeued == 30);
    assert(queue_available(queue) == 0);

    // Test dequeing an element when the queue is empty
    assert(queue_deque(queue, &dequeued) == false);  // Queue should be empty

    queue_delete(&queue);
}

void test_queue_peek() {
    // Create a queue and enqueue elements
    queue_t* queue = queue_create(sizeof(int), 5);
    int ele = 10;
    queue_enque(queue, &ele);
    ele = 20;
    queue_enque(queue, &ele);
    ele = 30;
    queue_enque(queue, &ele);

    // Test peeking at elements
    int peeked;
    assert(queue_peek(queue, &peeked) == true);
    assert(peeked == 10);

    // Test peeking at an element when the queue is empty
    queue_t* empty_queue = queue_create(sizeof(int), 5);
    assert(queue_peek(empty_queue, &peeked) == false);  // Queue should be empty

    queue_delete(&queue);
    queue_delete(&empty_queue);
}

void test_queue_is_empty() {
    // Create an empty queue
    queue_t* empty_queue = queue_create(sizeof(int), 5);

    // Test is_empty on an empty queue
    assert(queue_is_empty(empty_queue) == true);

    // Create a non-empty queue and enqueue elements
    queue_t* queue = queue_create(sizeof(int), 5);
    int ele = 10;
    queue_enque(queue, &ele);

    // Test is_empty on a non-empty queue
    assert(queue_is_empty(queue) == false);

    queue_delete(&queue);
    queue_delete(&empty_queue);
}

// Similarly, we can write tests for the other functions like queue_is_full, queue_available, and queue_size

int main() {
    test_queue_create();
    test_queue_enque();
    test_queue_deque();
    test_queue_peek();
    test_queue_is_empty();
    printf("All test passed!!!");
    return 0;
}
