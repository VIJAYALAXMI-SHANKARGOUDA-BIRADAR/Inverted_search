# 🔎📂 Inverted_search
# Inverted Search implemented in C using DSA concepts — Hash Table + Linked Lists for fast word indexing.


Inverted Search is a data-structure based C project that implements a fast word-search mechanism across multiple text files.
The project uses Hashing + Linked Lists to build an Inverted Index, a structure commonly used in search engines and document retrieval systems.

The program reads multiple text files, extracts all words, and stores them in a Hash Table of 27 buckets (a–z + others).
Each bucket contains a list of words (Main Nodes), and each word maintains a list of files (Sub Nodes) where it appears along with its index.

# 🚀 Features

Builds an Inverted Index using Hash Table (27 buckets)

Supports creating, displaying, searching, updating, saving the database

Stores file-wise word counts for accurate search results

Efficient lookup using hashing (O(1) average time)

Uses Linked Lists to store multiple files for a single word
# 📌 Why this project

To implement a fast inverted index using C + DSA concepts, improving search time using hashing and gaining real experience in system-level programming.

# Data Structures Used
   # 1)Slist (Single Linked List for File Names)
typedef struct file_node                       
{
    char name[50];
    struct file_node *link;
} Slist;

📌 Purpose:

To hold filenames before indexing

Used in read_validate()

Used in update_database() for removing old files


   # 2)Hash Table (htable)

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


  # 3)Main Node (m_node)

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

  # 4)Sub Node (s_node)

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

# Work Flow

<img width="601" height="711" alt="Screenshot 2025-11-22 183814" src="https://github.com/user-attachments/assets/5434cdbc-8d45-466c-8f3a-f29385076d57" />

# Advantages

Fast O(1) searching using hashing

Indexes multiple files efficiently

Saves & loads database without reprocessing files

Supports updating database dynamically

Memory-efficient inverted indexing

Modular, scalable, real-world DSA-based implementation



# Sample Output
      # Create Database
   <img width="981" height="747" alt="Screenshot 2025-11-22 192158" src="https://github.com/user-attachments/assets/bce8c7b4-d4af-485a-aa7a-aae877fc2b9a" />
   

     #  Display  Database
   <img width="1097" height="876" alt="Screenshot 2025-11-22 192213" src="https://github.com/user-attachments/assets/d2af2251-9feb-4373-816d-d1fd24a4678c" />
   

    #  Search Database
   <img width="881" height="599" alt="Screenshot 2025-11-22 192234" src="https://github.com/user-attachments/assets/0013cd61-3d34-42b5-aefd-0d13a57c82a7" />
   

     #  Save Database
  <img width="1121" height="444" alt="Screenshot 2025-11-22 192247" src="https://github.com/user-attachments/assets/4e718d43-b503-4f64-9b7c-7fc54be2b747" />
  


      #  Update Database

   <img width="1072" height="864" alt="Screenshot 2025-11-22 192257" src="https://github.com/user-attachments/assets/49553c0d-d6f3-4cc8-8b17-cbac22993cf4" />
<img width="949" height="836" alt="Screenshot 2025-11-22 192319" src="https://github.com/user-attachments/assets/8459edb6-cd49-447b-bdc4-668f3157fc1f" />
<img width="1204" height="864" alt="Screenshot 2025-11-22 192417" src="https://github.com/user-attachments/assets/5db229e1-5419-40df-972b-f200103e3161" />




         
      


# Applications:
Inverted Index is used in search engines, code editors, operating system search utilities, log analyzers, document management systems and email search.

# Conclusion
This project really helped me understand how searching works inside real applications. I built the complete inverted search system from scratch using C, hashing, and linked lists. By reading multiple files, extracting words, and storing them in a proper data structure, I learned how to make the search faster without scanning the full files again and again.

While doing this project, I faced many issues like segmentation faults, memory handling, linking main nodes and sub nodes correctly, and updating the database. Fixing these problems taught me how important it is to write clean logic and manage memory properly in C.

Overall, this project gave me confidence in DSA, file handling, and struct-based programming. It really felt like building a mini search engine on my own, and I now clearly understand how inverted indexing works in real-world search systems.






