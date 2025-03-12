Features
Abstract Base Class (ApstraktniStudent):

Stores common student attributes: name, surname, index number, exam count, and average grade.
Allows registration of exams and updates the student's average grade.
Provides virtual functions for displaying student data and creating copies of student objects.
Derived Classes:

StudentBachelor: Inherits from ApstraktniStudent and represents a Bachelor’s student. Displays specific student information.
StudentMaster: Inherits from ApstraktniStudent and represents a Master’s student, with an additional graduation year attribute.
Faculty Management (Fakultet):

Manages a collection of students using a dynamic array (vector).
Provides functionality to:
Enroll a student (either Bachelor's or Master's).
Remove a student by index number.
Access a student by index.
Sort and display all students by their average grade.
Implements copy and move constructors, as well as copy and move assignment operators to handle deep copies and resource management properly.
Error Handling:

Ensures students cannot be added with duplicate index numbers.
Throws exceptions when invalid exam grades are entered or when attempting to access a non-existent student.
Classes
ApstraktniStudent: Base class for both Bachelor and Master students.
StudentBachelor: Derived class for Bachelor students.
StudentMaster: Derived class for Master students.
Fakultet: Manages the students and provides functions for enrollment, removal, and display.