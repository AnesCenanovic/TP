This C++ program implements a student management system, managing both Bachelor's and Master's students. The system allows you to register students, add exam grades, and display student information.

Key Features:
Abstract Base Class (ApstraktniStudent): Represents a student with common attributes (name, surname, index, grades). Provides functions to register exams and calculate the average grade.
Derived Classes:
StudentBachelor: Represents a Bachelor's student.
StudentMaster: Represents a Master's student with an additional graduation year attribute.
Student Class: Manages student objects and handles memory management (deep copying and move semantics).
Functions:
Register Exam: RegistrirajIspit(int ocjena) to register an exam grade.
Reset Grades: PonistiOcjene() to reset grades.
Display Information: IspisiPodatke() to display student details.