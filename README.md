# Project: Document Search and Sorting System

## Overview
This project implements efficient algorithms and data structures to perform word frequency analysis, searching, and sorting on documents. The key components of the system include:

1. **Heap Sort** for efficient sorting based on word frequency.
2. **Hashtable** for fast insertion and searching of words.
3. **Linked List** to store word frequency with minimal memory leakage.
4. **Quotation Input** to locate specific phrases across multiple documents.

## Key Features

### 1. Heap Sort
To optimize sorting, we used the **Heap Sort** algorithm, reducing the time complexity from `O(n^2)` (as in Bubble Sort) to `O(n log n)`.

- **Heapify Process**:
  - Construct a max-heap tree using word frequency as data.
  - Parallel arrays are used to store document names and word frequencies.
  - Sorting swaps data in the array based on the algorithm.

### 2. Insertion and Searching in Hashtable
The hashtable efficiently manages word insertion and searching operations.

- **Process**:
  1. Open a file and read words sequentially.
  2. Convert capital letters to lowercase using a `small()` function.
  3. Generate a key using the `Hashkey()` function and insert the word at the key's index in a double-pointer array.
  4. Search for user-provided words, returning the count and document details if found.

### 3. Storing Word Frequency in Linked List
Linked lists are used to store word frequencies to ensure efficient memory usage and reduce insertion complexity to `O(1)`.

- **Process**:
  - Create a node for each document containing the word.
  - Store word frequency and document name in the node.
  - Link nodes for multiple documents sequentially.

### 4. Small Case Alphabets
To standardize and simplify searching, all words are converted to lowercase.

- **Process**:
  - Convert each character of a word to lowercase (if uppercase) by adding `32` to its ASCII value.
  - Ensure uniformity for both inserted and searched words.

### 5. Heapify Using Linked List Data
The frequency data from the linked list is used to build a binary tree for heap operations.

- **Process**:
  - Extract frequency data from the linked list.
  - Store data in an array and apply max-heap to sort by frequency.

### 6. Quotation Input
This feature allows users to search for a specific phrase or quotation across documents.

- **Process**:
  - Store up to 20 words in an array of size 20.
  - Open documents sequentially and search for the exact sequence of words.
  - Return the document name if the quotation is found.

## How It Works

1. **Read Words**: Words from a document are read and standardized to lowercase.
2. **Insert into Hashtable**: Words are hashed and inserted at the appropriate index.
3. **Search for Words**: User-provided keywords are hashed and searched in the hashtable.
4. **Store Frequencies**: Word frequencies are stored in a linked list for efficient memory management.
5. **Heap Sort**: Frequencies are sorted using the heap sort algorithm.
6. **Quotation Search**: Specific quotations are located by sequentially matching word sequences across documents.

## Advantages
- **Efficiency**: Reduced time complexity using heap sort and optimized data structures.
- **Memory Management**: Use of linked lists prevents memory leakage.
- **Scalability**: Handles up to 50 documents with complex word searches and frequency analysis.
- **User-Friendly**: Provides functionalities like lowercase conversion for seamless word matching.

---
