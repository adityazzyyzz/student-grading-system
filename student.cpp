#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student
{
private:
int marks[5];
vector<string> subjects = {"DCF", "UXD", "DBMS", "OOP", "WA"};
const int minMarks = 50;
public:
void getMarks()
{
for (int i = 0; i < 5; i++)
{
int mark;
cout << "Enter marks for " << subjects[i] << ": ";
cin >> mark;
while (mark < 0 || mark > 100)
{
cout << "Please enter marks between 0 and 100." << endl;
cout << "Enter marks for " << subjects[i] << ": ";
cin >> mark;
}
marks[i] = mark;
}
}
void result()
{
int failedSubjects = 0, totalMarks = 0;
int failedSubjectIndex = -1;
for (int i = 0; i < 5; i++)
{
totalMarks += marks[i];
if (marks[i] < minMarks)
{
failedSubjects++;
failedSubjectIndex = i;
}
}
if (failedSubjects == 0)
{
displayResult(totalMarks, "Pass");
}
else if (failedSubjects > 1)
{
cout << "Result: Fail" << endl;
}
else if (marks[failedSubjectIndex] >= 47)
{
int graceMarks = minMarks - marks[failedSubjectIndex];
cout << "Result: Pass with grace of " << graceMarks
<< " in " << subjects[failedSubjectIndex] << endl;
}
else
{
cout << "Result: Supplementary" << endl;
}
}
void displayResult(int totalMarks, string result)
{
double percentage = static_cast<double>(totalMarks) / 500 * 100;
string division = (percentage >= 70) ? "First Division" :
(percentage >= 60) ? "Second Division" :
"Third Division";
cout << "Total marks: " << totalMarks << endl;
cout << "Percentage: " << percentage << "%" << endl;
cout << "Division: " << division << endl;
cout << "Result: " << result << endl;
}
};
int main()
{
Student s;
s.getMarks();
s.result();
return 0;
}
