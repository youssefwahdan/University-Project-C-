#pragma once

using namespace System;

ref class Student
{
public:
    int StudentID;
    String^ Name;
    String^ Section;
    int AcademicYear;
};

ref class Subject
{
public:
    int SubjectID;
    String^ Name;
    int YearOffered;
};

ref class Grade
{
public:
    int GradeID;
    int StudentID;
    int SubjectID;
    Char Assignment1;
    Char Assignment2;
    double FinalGrade;
};