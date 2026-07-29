#include <iostream>
using namespace std;
struct SNode
{
	int SNO;
	SNode *Snext;
};
struct CNode
{
	int CNO;
	CNode *Cnext;
	SNode *Stu_list;
};
CNode *Clist = NULL;
// Insert Course
void insert_course(int CNO)
{
	CNode *temp = new CNode; // create a course
	temp->CNO = CNO;
	temp->Cnext = NULL;
	temp->Stu_list = NULL;
	if (Clist == NULL)
	{
		Clist = temp;
	}
	else
	{
		CNode *Ccur = Clist;
		while (Ccur->Cnext != NULL)
		{
			Ccur = Ccur->Cnext;
		}
		Ccur->Cnext = temp;
	}
}
// Unique Insert
void Insert(int value)
{
	CNode *temp = new CNode;
	temp->CNO = value;
	temp->Cnext = NULL;
	temp->Stu_list = NULL;
	if (Clist == NULL)
	{
		Clist = temp;
		return;
	}
	CNode *cur = Clist;
	while (cur != NULL)
	{
		if (cur->CNO == value)
		{
			cout << "dupliacte not allowed" << endl;
			delete (temp);
			return;
		}
		cur = cur->Cnext;
	}
	cur = Clist;
	while (cur->Cnext != NULL)
	{
		cur = cur->Cnext;
	}
	cur->Cnext = temp;
}
// Delete a course and its students
void delt(int CNO)
{
	if (Clist == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	CNode *pre = NULL;
	CNode *Ccur = Clist;
	// find course
	while (Ccur != NULL)
	{
		if (Ccur->CNO == CNO)
		{
			// find and delete student
			SNode *Scur = Ccur->Stu_list;
			while (Scur != NULL)
			{
				SNode *next = Scur->Snext;
				delete (Scur);
				Scur = next;
			}

			if (pre == NULL) // for first course
			{
				Clist = Ccur->Cnext;
			}
			else // for last and middle students
			{
				pre->Cnext = Ccur->Cnext;
			}
			delete (Ccur);
			cout << "Course deleted successfully ";
			return;
		}
		pre = Ccur;
		Ccur = Ccur->Cnext;
	}
	cout << "Course not found." << endl;
}
// Display a Course
void displayCourse()
{
	if (Clist == NULL)
	{
		cout << "Linked list is empty" << endl;
		return;
	}
	CNode *temp = Clist;
	cout << "=======Course list=======" << endl;
	while (temp != NULL)
	{
		cout << temp->CNO << "->";
		temp = temp->Cnext;
	}
	cout << "NULL\n";
}
// Search a course
void Search_Course(int CNO)
{
	if (Clist == NULL)
	{
		cout << "Linked list is empty" << endl;
		return;
	}
	int pos = 1;
	CNode *Ctemp = Clist;
	while (Ctemp != NULL)
	{
		if (Ctemp->CNO == CNO)
		{
			cout << Ctemp->CNO << " found at position " << pos;
			return;
		}
		Ctemp = Ctemp->Cnext;
		pos++;
	}
}
// Insert Student
void insert_student(int SNO, int CNO)
{
	// traverse the course list
	CNode *Ccur = Clist;
	while (Ccur != NULL)
	{
		if (Ccur->CNO == CNO)
		{
			// if course no exist than insert
			SNode *Stemp = new SNode;
			Stemp->SNO = SNO;
			Stemp->Snext = NULL;
			if (Ccur->Stu_list == NULL) // for first student
			{
				Ccur->Stu_list = Stemp;
			}

			else // for middle and last student
			{
				SNode *Scur = Ccur->Stu_list;
				while (Scur->Snext != NULL)
				{
					Scur = Scur->Snext;
				}
				Scur->Snext = Stemp;
			}
			return;
		}
		Ccur = Ccur->Cnext;
	}
}
// Delete a Student from a Course
void DeleteStu(int CNO, int SNO)
{
	if (Clist == NULL)
	{
		cout << "List is empty" << endl;
	}
	// find course
	CNode *Ccur = Clist;
	while (Ccur != NULL)
	{
		if (Ccur->CNO == CNO)
		{
			SNode *Scur = Ccur->Stu_list;
			SNode *Spre = NULL;
			while (Scur != NULL)
			{
				if (Scur->SNO == SNO) // find student
				{
					if (Spre == NULL) // for first student
					{
						Ccur->Stu_list = Scur->Snext;
					}
					else // for middle and last student
					{
						Spre->Snext = Scur->Snext;
					}
					delete Scur;
					cout << "Student deleted successfully" << endl;
					return;
				}
				Spre = Scur;
				Scur = Scur->Snext;
			}
			cout << "Student not found" << endl;
			return;
		}
		Ccur = Ccur->Cnext;
	}
	cout << "Course not found" << endl;
}
// delete a student
void DelStu(int SNO)
{
	if (Clist == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	// find course
	CNode *Ccur = Clist;
	while (Ccur != NULL)
	{
		SNode *Scur = Ccur->Stu_list;
		SNode *Spre = NULL;
		while (Scur != NULL)
		{
			if (Scur->SNO == SNO) // find student
			{
				if (Spre == NULL) // for first student
				{
					Ccur->Stu_list = Scur->Snext;
				}
				else // for middle and last student
				{
					Spre->Snext = Scur->Snext;
				}
				SNode *temp = Scur; // save node
				Scur = Scur->Snext; // move forward
				delete temp;

				cout << "Student deleted successfully" << endl;
			}
			Spre = Scur;
			Scur = Scur->Snext;
		}
		Ccur = Ccur->Cnext;
	}
	cout << "Student not found" << endl;
}
// Search Student In A Course
void searchStudentInCourse(int CNO, int SNO)
{
	if (Clist == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	CNode *Ccur = Clist;

	// Search for the course
	while (Ccur != NULL)
	{
		if (Ccur->CNO == CNO)
		{
			// Course found, now search student
			SNode *Scur = Ccur->Stu_list;

			while (Scur != NULL)
			{
				if (Scur->SNO == SNO)
				{
					cout << Scur->SNO << " found at course no " << CNO;
					return;
				}
				Scur = Scur->Snext;
			}

			// Student not found in this course
			cout << "Seat NO Not Found";
			return;
		}

		Ccur = Ccur->Cnext;
	}

	// Course not found
	printf("Course No Not Found");
}
// Search Student in all course
void searchStudent(int SNO)
{
	if (Clist == NULL)
	{
		cout << "List is empty.\n";
		return;
	}

	CNode *Ccur = Clist;

	// Traverse all courses
	while (Ccur != NULL)
	{
		SNode *Scur = Ccur->Stu_list;

		// Traverse students of current course
		while (Scur != NULL)
		{
			if (Scur->SNO == SNO)
			{
				cout << Scur->SNO << " found at course no" << endl;
				return;
			}
			Scur = Scur->Snext;
		}

		Ccur = Ccur->Cnext;
	}

	// Student not found in any course
	cout << "Student not found";
}

// Display All
void displayAll()
{
	if (Clist == NULL)
	{
		cout << "Linked List is empty\n";
		return;
	}
	// course list display
	CNode *temp = Clist;
	cout << "=======Course and Student list======== " << endl;

	while (temp != NULL)
	{
		cout << temp->CNO << " -> ";

		// student list display
		SNode *Scur = temp->Stu_list;

		if (Scur == NULL)
		{
			cout << "No Student";
		}
		else
		{
			while (Scur != NULL)
			{
				cout << Scur->SNO << " -> ";
				Scur = Scur->Snext;
			}
			cout << "NULL";
		}

		cout << endl;
		temp = temp->Cnext;
	}
}
int main()
{
	// insert_course(451);
	// insert_course(453);
	// insert_course(455);
	// insert_course(457);
	// insert_course(459);
	// insert_course(461);

	Insert(451);
	Insert(453);
	Insert(455);
	Insert(457);
	Insert(459);
	Insert(459);
	displayCourse();

	insert_student(02, 451);
	insert_student(01, 453);
	insert_student(02, 453);
	insert_student(03, 453);
	displayAll();

	DelStu(02);
	displayAll();
	// //searchStudentInCourse(453,02);
	// searchStudent(02);
	// // delt(453);
	// // DeleteStu(453, 02);
	// displayAll();
	return 0;
}
