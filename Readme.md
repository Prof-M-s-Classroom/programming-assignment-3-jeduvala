[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Jed Eduvala

## Description
This program uses Prim's Algorithm to find the MST of different graphs.
I used an adjacency matrix to represent the graph and created a minHeap to select the smallest vertices.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log n)        |
| Extract Min          | O(log n)        |
| Decrease Key         | O(log n)        |
| Prim’s MST Overall   | O(n^2  )        |

_Explain why your MST implementation has the above runtime._

The graph uses is put into an adjacency matrix to scan all the nodes (O(n^2)). 
The extraction and decrease head operations are O(log n).
Total run time is O(n^2) and this is plausible since it's less than 10 vertices.

## Test Case Description

Input:  

(0, 1) → 2
(0, 3) → 6
(1, 2) → 3
(1, 3) → 8
(1, 4) → 5
(2, 4) → 7
(3, 4) → 9