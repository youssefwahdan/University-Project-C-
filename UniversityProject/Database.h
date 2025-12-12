
#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

ref class Database
{
private:
    // String^ connectionString; // Remove this line, as connectionString will be public

public:
    static System::String^ connectionString; // Make connectionString public and static

    Database(String^ connStr);

    DataTable^ GetStudents();
    bool AddStudent(String^ name, String^ section, int year);
    bool UpdateStudent(int studentId, String^ name, String^ section, int year);
    bool DeleteStudent(int studentId);
	bool AddOrUpdateGrade(int studentId, int subjectId, String^ assignment1, String^ assignment2, double finalGrade);
	bool AddOrUpdateGrade(int studentId, int subjectId, int assignment1, int assignment2, double finalGrade);
	bool DeleteGrade(int gradeId);
	//bool DeleteGradesByStudent(int studentId);
	//bool DeleteGradesBySubject(int subjectId);
	//bool UpdateSubject(int subjectId, String^ name, int yearOffered);
	//bool DeleteSubject(int subjectId);
	//bool SubjectExists(String^ name, int yearOffered);
	DataTable^ GetGrades();
	//DataTable^ GetGradesByStudent(int studentId);
	//DataTable^ GetGradesBySubject(int subjectId);
	//DataTable^ GetGradesByStudentAndSubject(int studentId, int subjectId);
	//DataTable^ GetSubjectsByYear(int yearOffered);
	//DataTable^ GetStudentsByYear(int year);
	//DataTable^ GetStudentsBySection(String^ section);
	//DataTable^ GetStudentById(int studentId);
	//DataTable^ GetSubjectById(int subjectId);
	//DataTable^ GetGradeById(int gradeId);
	//DataTable^ GetGradesSummary();
	//DataTable^ GetStudentsByName(String^ name);
	//DataTable^ GetStudentsBySectionAndYear(String^ section, int year);
	//DataTable^ GetStudentsByNameSectionAndYear(String^ name, String^ section, int year);
	//DataTable^ GetSubjectsByName(String^ name);
	//DataTable^ GetSubjectsByYearOffered(int yearOffered);

    DataTable^ GetSubjects();
    bool AddSubject(String^ name, int yearOffered);
    // ... More methods for Grades, etc.
};