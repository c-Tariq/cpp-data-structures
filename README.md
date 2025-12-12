
# **Student Database Management System**

This C++ program manages student records using two data structures: a **Binary Search Tree (BST)** and a **Linked List**. It allows adding, removing, searching, and analyzing students, as well as generating performance reports.

---

## **Features**

* Add new students
* Remove students by ID
* Search for students
* Display students stored in the Binary Tree (sorted by ID)
* Display students stored in the Linked List (sorted by grade)
* Generate class report (average grade + top 3 students)

---

## **Student Structure**

Each student record contains:

* `id`
* `name`
* `address`
* `date_of_birth`
* `contact_information`
* `grade`
* `attendance`

---

## **Classes Overview**

### **1. BinaryTree**

Stores students in a BST organized by student ID.

**Key Methods**

* `BinaryTree()` — initializes an empty tree
* `buildTree(Student&)` — adds a student
* `removeStudent(int)` — removes a student by ID
* `display()` — prints students in descending order
* `searchbst(int)` — searches for a student by ID
* `~BinaryTree()` — deallocates memory

---

### **2. Linklist**

Stores students in descending order of their grades.

**Key Methods**

* `Linklist()` — initializes an empty list
* `add(Student&)` — adds a student
* `del(int)` — deletes a student by ID
* `average()` — prints the class average and performance
* `top()` — shows the top 3 students

---

### **3. StudentDatabase**

Provides a unified interface that manages both data structures.

**Key Methods**

* `StudentDatabase()` — initializes BinaryTree and Linklist
* `addStudent(Student)` — adds a student to both structures
* `removeStudent(int)` — removes a student from both
* `searchStudent(int)` — searches via the BST
* `report()` — generates the class report
* `displayLinklist()` — prints all students in the Linked List
* `displayTree()` — prints all students in the Binary Tree

