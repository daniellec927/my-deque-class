# Deque Class (C++)

A templated double-ended queue (deque) implemented with a doubly linked list,
plus a `Garage` demo that uses it as a fixed-capacity, most-recently-used store
(older items are purged when the garage is full).

## Structure
| File | Purpose |
|------|---------|
| `DequeNode.h` / `DequeNode.cpp` | Node holding a value and prev/next links. |
| `Deque.h` / `Deque.cpp` | Templated deque: addToFront/Rear, deleteFront/Rear, get, front, rear, printItems. |
| `Garage.h` / `Garage.cpp` | Fixed-capacity container built on the deque. |
| `main.cpp` | Test driver exercising the deque and garage. |

## Build & Run
```bash
g++ -std=c++17 main.cpp Garage.cpp -o deque
./deque
```
> Note: because `Deque` and `DequeNode` are templated, their `.cpp` files are
> `#include`d through the headers. This is intentional for this assignment's setup.
