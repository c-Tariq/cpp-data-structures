#include <iostream>
#include <iomanip>
using namespace std;

struct Student
{
	int id;
	string name;
	string address;
	string date_of_birth;
	string contact_information;
	double grade;
	string attendance;

};
struct BinaryTreeNode
{
	Student student;
	BinaryTreeNode* leftchild;
	BinaryTreeNode* rightchild;
};

class BinaryTree
{
private:
	BinaryTreeNode* root;

	void insert(BinaryTreeNode** sr, Student& newStudent)
	{ // students will be sorted according to their ID.
		if (*sr == NULL)
		{
			*sr = new BinaryTreeNode;
			(*sr)->student = newStudent;
			(*sr)->leftchild = NULL;
			(*sr)->rightchild = NULL;
		}
		else
		{
			//if the student to be inserted has an ID that is less than the current student go to the left else go right
			if (newStudent.id < (*sr)->student.id)
			{
				insert(&((*sr)->leftchild), newStudent);
			}
			else
			{
				insert(&((*sr)->rightchild), newStudent);
			}
		}
	}

	void inorder(BinaryTreeNode* sr)
	{
		if (sr != NULL)
		{
			inorder(sr->rightchild);
			cout << "\nID: " << sr->student.id << "\t\tName: " << sr->student.name << "\tGrade: " << sr->student.grade << "\tAttendance: " << sr->student.attendance;
			cout << "\nAddress: " << sr->student.address << "\tDate of Birth: " << sr->student.date_of_birth << "\tContact Information: " << sr->student.contact_information << endl;
			inorder(sr->leftchild);
		}

	}

	void remove(BinaryTreeNode** sr, int id)
	{
		if (*sr == NULL)
		{
			return;
		}
		else if (id < (*sr)->student.id)
		{
			remove(&((*sr)->leftchild), id);
		}
		else if (id > (*sr)->student.id)
		{
			remove(&((*sr)->rightchild), id);
		}
		else
		{	// if the node to be deleted is a leaf node, just delete it.
			if ((*sr)->leftchild == NULL && (*sr)->rightchild == NULL)
			{
				delete *sr;
				*sr = NULL;
				return;
			}
			// if the node to be deleted has only a right child, replace the node with it.
			else if ((*sr)->leftchild == NULL)
			{
				BinaryTreeNode* temp = *sr;
				*sr = (*sr)->rightchild;
				delete temp;
				return;
			}
			// if the node to be deleted has only a left child, replace the node with it.
			else if ((*sr)->rightchild == NULL)
			{
				BinaryTreeNode* temp = *sr;
				*sr = (*sr)->leftchild;
				delete temp;
				return;
			}
			else
			{
				BinaryTreeNode* temp = findMin((*sr)->rightchild);
				(*sr)->student = temp->student;  // Copy the successor's data
				remove(&((*sr)->rightchild), temp->student.id);  // Delete the successor
				return;
			}

		}
	}

	BinaryTreeNode* findMin(BinaryTreeNode* sr)
	{
		while (sr->leftchild != NULL)
		{
			sr = sr->leftchild;
		}
		return sr;
	}


	void search(BinaryTreeNode* sr, int id) {

		if (sr == NULL)
		{
			cout << "\nThere is no student with the ID: " << id << " in the Database" << endl;
			return;
		}
		if (id == sr->student.id)
		{
			cout << "\n\nID: " << sr->student.id << "\t\tName: " << sr->student.name << "\tGrade: " << sr->student.grade << "\tAttendance: " << sr->student.attendance;
			cout << "\nAddress: " << sr->student.address << "\tDate of Birth: " << sr->student.date_of_birth << "\tContact Information: " << sr->student.contact_information << endl;
			return;
		}
		if (id < sr->student.id)
		{
			return search(sr->leftchild, id);
		}
		return search(sr->rightchild, id);
	}
public:
	BinaryTree()
	{
		root = NULL;
	}
	void buildTree(Student& student)
	{
		insert(&root, student);
	}
	void removeStudent(int id)
	{
		remove(&root, id);
	}
	void display()
	{
		inorder(root);
	}
	void searchbst(int id)
	{
		search(root, id);
	}
	void del(BinaryTreeNode* sr)
	{
		if (sr != NULL)
		{
			del(sr->leftchild);
			del(sr->rightchild);
		}
		delete sr;
	}
	~BinaryTree()
	{
		del(root);
	}

};

class Linklist {
private: 
	struct node
	{
		Student student;
		node* link;
	};
	node* head;
public:
	Linklist()
	{
		head = NULL;
	}
	~Linklist()
	{
		node* current = head;
		while (current != NULL)
		{
			node* next = current->link;
			delete current;
			current = next;
		}
		head = NULL;
	}
	void add(Student& newStudent)
	{
		node* newNode = new node;
		newNode->student = newStudent;
		newNode->link = NULL;
		node* temp = NULL;
		// if there is no nodes in the list or the new student has higher grade than the student in the head, put him at the beginning.
		if (head == NULL || newStudent.grade > head->student.grade)
		{
			newNode->link = head;
			head = newNode;
		}
		else
		{
			temp = head;
			// this while loop will find the proper place for the newStudent
			while (temp->link != NULL && temp->link->student.grade > newStudent.grade)
			{
				temp = temp->link;
			}
			newNode->link = temp->link;
			temp->link = newNode;
		}
	}
	void del(int id)
	{
		node* prev = NULL;
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->student.id == id)
			{
				// if the node to be deleted is the first node in the linked list, make the head points to the next node.
				if (temp == head)
					head = temp->link;
				else
					prev->link = temp->link;
				// free the memory occupied by the node
				delete temp;
				return;
			}
			else
			{
				prev = temp;
				temp = temp->link;
			}
		}
		cout << "There is no student with the ID: " << id << " in the Database" << endl;
	}

	void display()
	{
		node* sr = head;
		while (sr != NULL)
		{
			cout << "\nID: "<< sr->student.id << "\t\tName: " << sr->student.name << "\tGrade: " << sr->student.grade << "\tAttendance: " << sr->student.attendance;
			cout << "\nAddress: " << sr->student.address << "\tDate of Birth: " << sr->student.date_of_birth << "\tContact Information: " << sr->student.contact_information << endl;
			sr = sr->link;
		}
	}
	int search(int id) // This function is only used to check before inserting a new student.
	{
		node* temp;
		temp = head;
		while (temp != NULL)
		{
			if (temp->student.id == id)
			{
				return 1;
			}
			temp = temp->link;
		}
		return 0;
	}
	void average()
	{
		double total, sum = 0;
		int count = 0;
		node* currentNode = head;
		if (currentNode == NULL) {
			cout << "\n\nNo students in the class." << endl;
			return;
		}
		while (currentNode != NULL)
		{
			sum += currentNode->student.grade;
			currentNode = currentNode->link;
			count++;
		}
		total = sum / count;
		cout << "\n\nThe average grade of the class is: " << fixed << setprecision(2) << total;

		switch ((int)total / 10)
		{
		case 10:
		case 9:
			cout << "\nThe Overall performance is 'Excellent'. \n";
			break;
		case 8:
			cout << "\nThe Overall  performance is 'Very Good'. \n";
			break;
		case 7:
			cout << "\nThe Overall  performance is 'Good'.\n";
			break;
		case 6:
			cout << "\nThe Overall performance is 'Passable'.\n";
			break;
		default:
			cout << "\nThe Overall performance is 'Poor'.\n";
		}
	}
	void top()
	{
		node* currentNode = head;
		int counter = 0;
		cout << "\nTop 3 performing students:";
		while (currentNode != NULL && counter < 3) // Only top 3 Students will be printed
		{
			cout << "\nName: " << currentNode->student.name << "\tGrade: " << currentNode->student.grade << "\tAttendance: " << currentNode->student.attendance;
			currentNode = currentNode->link;
			counter++;
		}

	}
};

class StudentDatabase {
private:
	Linklist* list;
	BinaryTree* tree;
public:
	StudentDatabase() {

		list = new Linklist();
		tree = new BinaryTree();

	}
	~StudentDatabase() {
		delete list;
		delete tree;
	}
	void addStudent(Student s)
	{
		if (s.grade < 0 || s.grade > 100) {
			cout << "Invalid grade for student ID: " << s.id << endl;
			return;
		}
		if (list->search(s.id)) // We must make sure that there is no student with the same id before inserting in the Database .
		{
			cout << "There is a student with the ID: " << s.id << " in the Database" << endl;
			return;
		}
		list->add(s);
		tree->buildTree(s);
	}
	void removeStudent(int id)
	{
		list->del(id);
		tree->removeStudent(id);
	}
	void searchStudent(int id)
	{
		tree->searchbst(id);
	}
	void report()
	{
		list->average();
		list->top();
	}
	void displayTree()
	{
		tree->display();
	}
	void displayLinklist()
	{
		list->display();
	}
};


int main()
{

	StudentDatabase A, B; // Create 2 Classes A, B
	Student students[8] = {
	{ 112, "Badr", "135 Main Street", "1999-01-01", "(123) 456-7890", 89, "87%" },
	{ 109, "Nayef", "168 Main Street", "1998-07-01", "(123) 456-7890", 67, "74%" },
	{ 114, "Ahmad", "123 Main Street", "2002-03-01", "(123) 456-7890", 86, "80%" },
	{ 120, "Saad", "421 Main Street", "2001-09-01", "(123) 456-7890", 82, "86%" },
	{ 116, "Mohammed", "421 Main Street", "2002-09-07", "(123) 456-7890", 90, "87%" },
	{ 113, "Faisal", "234 Main Street", "2004-06-01", "(123) 456-7890", 94, "90%" },
	{ 110, "Rayan", "186 Main Street", "1999-05-01", "(123) 456-7890", 97, "100%" },
	{ 119, "Fahad", "179 Main Street", "1999-07-01", "(123) 456-7890", 91, "93%" }
	};
	for (int i = 0; i < 4; i++)
	{
		A.addStudent(students[i]);
	}
	for (int i = 4; i < 8; i++)
	{
		B.addStudent(students[i]);
	}
	A.report();
	B.report();

	B.removeStudent(110);
	B.searchStudent(119);
	B.searchStudent(110);

	return 0;
}