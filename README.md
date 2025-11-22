# Inverted_search
Inverted Search implemented in C using DSA concepts — Hash Table + Linked Lists for fast word indexing.


Inverted Search is a data-structure based C project that implements a fast word-search mechanism across multiple text files.
The project uses Hashing + Linked Lists to build an Inverted Index, a structure commonly used in search engines and document retrieval systems.

The program reads multiple text files, extracts all words, and stores them in a Hash Table of 27 buckets (a–z + others).
Each bucket contains a list of words (Main Nodes), and each word maintains a list of files (Sub Nodes) where it appears along with its index.
