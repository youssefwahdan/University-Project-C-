#include "Database.h"

Database::Database(String^ connStr)
{
    connectionString = connStr;
}

DataTable^ Database::GetStudents() {
    DataTable^ dt = gcnew DataTable();
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    try {
        String^ query = "SELECT * FROM Students";
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, conn);
        adapter->Fill(dt);
    }
    finally {
        if (conn != nullptr)
            delete conn;
    }
    return dt;
}

bool Database::AddStudent(String^ name, String^ section, int year) {
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    try {
        String^ query = "INSERT INTO Students (Name, Section, AcademicYear) VALUES (@Name, @Section, @Year)";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@Name", name);
        cmd->Parameters->AddWithValue("@Section", section);
        cmd->Parameters->AddWithValue("@Year", year);
        conn->Open();
        return cmd->ExecuteNonQuery() == 1;
    }
    finally {
        if (conn != nullptr)
            delete conn;
    }
}

DataTable^ Database::GetGrades()
{
    DataTable^ dt = gcnew DataTable();
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    try
    {
        String^ query = "SELECT * FROM Grades";
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, conn);
        adapter->Fill(dt);
    }
    finally
    {
        if (conn != nullptr)
            delete conn;
    }
    return dt;
}

bool Database::AddOrUpdateGrade(int studentId, int subjectId, String^ assignment1, String^ assignment2, double finalGrade)
{
    SqlConnection^ conn = nullptr;
    try
    {
        conn = gcnew SqlConnection(connectionString);
        conn->Open();

        // Check if grade exists
        String^ checkQuery = "SELECT COUNT(*) FROM Grades WHERE StudentId = @studentId AND SubjectId = @subjectId";
        SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
        checkCmd->Parameters->AddWithValue("@studentId", studentId);
        checkCmd->Parameters->AddWithValue("@subjectId", subjectId);

        int count = (int)checkCmd->ExecuteScalar();

        String^ query;
        if (count > 0)
        {
            // Update existing grade
            query = "UPDATE Grades SET Assignment1 = @assignment1, Assignment2 = @assignment2, FinalGrade = @finalGrade WHERE StudentId = @studentId AND SubjectId = @subjectId";
        }
        else
        {
            // Insert new grade
            query = "INSERT INTO Grades (StudentId, SubjectId, Assignment1, Assignment2, FinalGrade) VALUES (@studentId, @subjectId, @assignment1, @assignment2, @finalGrade)";
        }

        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@studentId", studentId);
        cmd->Parameters->AddWithValue("@subjectId", subjectId);
        cmd->Parameters->AddWithValue("@assignment1", assignment1);
        cmd->Parameters->AddWithValue("@assignment2", assignment2);
        cmd->Parameters->AddWithValue("@finalGrade", finalGrade);

        int rowsAffected = cmd->ExecuteNonQuery();
        return rowsAffected > 0;
    }
    catch (Exception^)
    {
        return false;
    }
    finally
    {
        if (conn != nullptr)
            delete conn;
    }
}

bool Database::AddOrUpdateGrade(int studentId, int subjectId, int assignment1, int assignment2, double finalGrade)
{
    SqlConnection^ conn = nullptr;
    try
    {
        conn = gcnew SqlConnection(connectionString);
        conn->Open();

        // Check if grade exists
        String^ checkQuery = "SELECT COUNT(*) FROM Grades WHERE StudentId = @studentId AND SubjectId = @subjectId";
        SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
        checkCmd->Parameters->AddWithValue("@studentId", studentId);
        checkCmd->Parameters->AddWithValue("@subjectId", subjectId);

        int count = (int)checkCmd->ExecuteScalar();

        String^ query;
        if (count > 0)
        {
            // Update existing grade
            query = "UPDATE Grades SET Assignment1 = @assignment1, Assignment2 = @assignment2, FinalGrade = @finalGrade WHERE StudentId = @studentId AND SubjectId = @subjectId";
        }
        else
        {
            // Insert new grade
            query = "INSERT INTO Grades (StudentId, SubjectId, Assignment1, Assignment2, FinalGrade) VALUES (@studentId, @subjectId, @assignment1, @assignment2, @finalGrade)";
        }

        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@studentId", studentId);
        cmd->Parameters->AddWithValue("@subjectId", subjectId);
        cmd->Parameters->AddWithValue("@assignment1", assignment1);
        cmd->Parameters->AddWithValue("@assignment2", assignment2);
        cmd->Parameters->AddWithValue("@finalGrade", finalGrade);

        int rowsAffected = cmd->ExecuteNonQuery();
        return rowsAffected > 0;
    }
    catch (Exception^)
    {
        return false;
    }
    finally
    {
        if (conn != nullptr)
            delete conn;
    }
}

bool Database::UpdateStudent(int studentId, String^ name, String^ section, int year) {
    try {
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        String^ query = "UPDATE Students SET Name = @Name, Section = @Section, AcademicYear = @Year WHERE StudentId = @StudentId";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@Name", name);
        cmd->Parameters->AddWithValue("@Section", section);
        cmd->Parameters->AddWithValue("@Year", year);
        cmd->Parameters->AddWithValue("@StudentId", studentId);

        conn->Open();
        int rowsAffected = cmd->ExecuteNonQuery();
        conn->Close();

        return rowsAffected > 0;
    }
    catch (Exception^) {
        return false;
    }
}

bool Database::DeleteStudent(int studentId) {
    try {
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        String^ query = "DELETE FROM Students WHERE StudentId = @StudentId";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@StudentId", studentId);

        conn->Open();
        int rowsAffected = cmd->ExecuteNonQuery();
        conn->Close();

        return rowsAffected > 0;
    }
    catch (Exception^) {
        return false;
    }
}

bool Database::DeleteGrade(int gradeId)
{
    try
    {
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        String^ query = "DELETE FROM Grades WHERE GradeId = @GradeId";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@GradeId", gradeId);

        conn->Open();
        int rowsAffected = cmd->ExecuteNonQuery();
        conn->Close();

        return rowsAffected > 0;
    }
    catch (Exception^)
    {
        return false;
    }
}

DataTable^ Database::GetSubjects()
{
    DataTable^ dt = gcnew DataTable();
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM Subjects";
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, conn);
        adapter->Fill(dt);
    }
    catch (Exception^ ex)
    {
        // Handle exception (log or rethrow as needed)
    }
    finally
    {
        conn->Close();
    }
    return dt;
}

bool Database::AddSubject(String^ name, int yearOffered)
{
    try
    {
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        String^ query = "INSERT INTO Subjects (Name, YearOffered) VALUES (@name, @yearOffered)";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@name", name);
        cmd->Parameters->AddWithValue("@yearOffered", yearOffered);

        conn->Open();
        int rowsAffected = cmd->ExecuteNonQuery();
        conn->Close();

        return rowsAffected > 0;
    }
    catch (Exception^)
    {
        return false;
    }
}


