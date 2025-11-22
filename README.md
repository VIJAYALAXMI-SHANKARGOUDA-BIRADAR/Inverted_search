# 🔎📂 Inverted_search
# Inverted Search implemented in C using DSA concepts — Hash Table + Linked Lists for fast word indexing.


Inverted Search is a data-structure based C project that implements a fast word-search mechanism across multiple text files.
The project uses Hashing + Linked Lists to build an Inverted Index, a structure commonly used in search engines and document retrieval systems.

The program reads multiple text files, extracts all words, and stores them in a Hash Table of 27 buckets (a–z + others).
Each bucket contains a list of words (Main Nodes), and each word maintains a list of files (Sub Nodes) where it appears along with its index.

#🚀 Features

Builds an Inverted Index using Hash Table (27 buckets)

Supports creating, displaying, searching, updating, saving the database

Stores file-wise word counts for accurate search results

Efficient lookup using hashing (O(1) average time)

Uses Linked Lists to store multiple files for a single word

# Data Structures Used
#1)Slist (Single Linked List for File Names)
typedef struct file_node                       
{
    char name[50];
    struct file_node *link;
} Slist;

📌 Purpose:

To hold filenames before indexing

Used in read_validate()

Used in update_database() for removing old files


#2)Hash Table (htable)

Hash table of 27 buckets.

📌 Structure:
typedef struct hash_table
{
    int index;
    struct main_node *link;
} htable;

Purpose:

Faster search

Avoid sorting

Each bucket stores words starting with:

a to z → bucket 0–25

others → bucket 26

✔ Hash index formula:
index = word[0] - 'a'


#3)Main Node (m_node)

Stores unique words.

📌 Structure:
typedef struct main_node
{
    char word[50];
    int file_count;
    struct sub_node *s_link;
    struct main_node *m_link;
} m_node;

📌 Purpose:

Hold one word

Store how many files contain that word

Point to first sub node

Point to next main node

4)Sub Node (s_node)

Stores file details for each word.

📌 Structure:
typedef struct sub_node
{
    char file_name[50];
    int word_count;
    struct sub_node *sublink;
} s_node;

📌 Purpose:

Store the filename

Count of word in that file

Link to next sub node (another file)

#Work Flow

<img width="601" height="711" alt="Screenshot 2025-11-22 183814" src="https://github.com/user-attachments/assets/5434cdbc-8d45-466c-8f3a-f29385076d57" />



