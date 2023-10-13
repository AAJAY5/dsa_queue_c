#ifndef __QUEUE_H__
#define __QUEUE_H__

/**
 * @file queue.h
 * @brief This is the header file for the queue data structure in C.
 */

#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/**
 * @struct queue_t
 * @brief Structure representing a queue.
 *
 * This structure holds the necessary information to manage a queue.
 */
typedef struct
{
    size_t e_size;    /**< The size of each element in the queue */
    size_t e_count;   /**< The maximum number of elements the queue can hold */
    size_t head;      /**< The index of the head of the queue */
    size_t tail;      /**< The index of the tail of the queue */
    size_t count;     /**< The current number of elements in the queue */
    void *mem;        /**< The memory block storing the queue elements */
} queue_t;

/**
 * @brief Create a new queue.
 * 
 * @param e_size The size of each element in the queue.
 * @param e_count The maximum number of elements the queue can hold.
 * @return A pointer to the newly created queue.
 */
queue_t *queue_create(size_t e_size, size_t e_count);

/**
 * @brief Enqueue an element into the queue.
 *
 * This function adds a new element to the tail of the queue.
 *
 * @param queue A pointer to the queue.
 * @param ele A pointer to the element to be enqueued.
 * @return True if the element was successfully enqueued, false otherwise.
 */
bool queue_enque(queue_t *queue, void *ele);

/**
 * @brief Dequeue an element from the queue.
 *
 * This function removes an element from the head of the queue.
 *
 * @param queue A pointer to the queue.
 * @param ele A pointer to store the dequeued element.
 * @return True if an element was successfully dequeued, false otherwise.
 */
bool queue_deque(queue_t *queue, void *ele);

/**
 * @brief Peek at the element at the head of the queue.
 *
 * This function retrieves the element at the head of the queue, without removing it.
 *
 * @param queue A pointer to the queue.
 * @param ele A pointer to store the peeked element.
 * @return True if an element was successfully peeked, false otherwise.
 */
bool queue_peek(queue_t *queue, void *ele);

/**
 * @brief Check if the queue is empty.
 *
 * This function checks if the queue is empty.
 * 
 * @param queue A pointer to the queue.
 * @return True if the queue is empty, false otherwise.
 */
bool queue_is_empty(queue_t *queue);

/**
 * @brief Check if the queue is full.
 *
 * This function checks if the queue is full.
 * 
 * @param queue A pointer to the queue.
 * @return True if the queue is full, false otherwise.
 */
bool queue_is_full(queue_t *queue);

/**
 * @brief Get the number of available to read in the queue.
 *
 * @param queue A pointer to the queue.
 * @return The number of available to read in the queue.
 */
size_t queue_available(queue_t *queue);

/**
 * @brief Get the size of the queue.
 *
 * @param queue A pointer to the queue.
 * @return The current number of elements in the queue.
 */
size_t queue_size(queue_t *queue);

/**
 * @brief Delete the queue and free the allocated memory.
 *
 * This function deletes the queue and frees the memory allocated for it.
 * 
 * @param queue A double pointer to the queue.
 */
void queue_delete(queue_t **queue);

#endif
