#include "Database.h"

Database::Database(String^ connStr)
{
    connectionString = connStr;
}

DataTable^ Database::GetStudents() {
    DataTable^ dt = gcnew DataTable();
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    try {
        String^ query = "SELECT * FROM Student";
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, conn);
        adapter->Fill(dt);
    }
    finally {
        if (conn != nullptr)
            delete conn;
    }
    return dt;
}

bool Database::AddStudent(String^ firstName, String^ lastName,String^ UniversityID, String^ gender) {
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    try {
        String^ query = "INSERT INTO Student (FirstName, LastName, UniversityID, Gender) VALUES (@FirstName,@LastName,@UniversityID, @Gender)";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@FirstName", firstName);
        cmd->Parameters->AddWithValue("@LastName", lastName);
        cmd->Parameters->AddWithValue("@UniversityID", UniversityID);
        cmd->Parameters->AddWithValue("@Gender", gender);
        conn->Open();
        return cmd->ExecuteNonQuery() == 1;
    }
    finally {
        if (conn != nullptr)
            delete conn;
    }
}

DataTable^ Database::GetAcademicYears()
{
    DataTable^ dt = gcnew DataTable();
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    try
    {
        String^ query = "SELECT * FROM AcademicYear";
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

bool Database::UpdateStudent(int studentId, String^ firstName, String^ lastName, String^ UniversityID, String^ Gender) {
    try {
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        String^ query = "UPDATE Student SET FirstName = @FirstName,LastName = @LastName,UniversityID = @UniversityID , Gender = @Gender WHERE StudentId = @StudentId";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@FirstName", firstName);
        cmd->Parameters->AddWithValue("@LastName", lastName);
        cmd->Parameters->AddWithValue("@UniversityID", UniversityID);
        cmd->Parameters->AddWithValue("@Gender", Gender);
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
        String^ query = "DELETE FROM Student WHERE StudentID = @StudentId";
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
SqlDataReader^ Database::LoadStudentData(int id)
{
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM Student WHERE StudentID = @id";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}
SqlDataReader^ Database::LoadDepartmentData(int id)
{
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM Department WHERE DepartmentID = @id";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}
SqlDataReader^ Database::LoadFacultyData(int id)
{
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM Faculty WHERE FacultyID = @id";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}
SqlDataReader^ Database::LoadAcademicLevelData(int id)
{
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM AcademicLevel WHERE AcademicLevelID = @id";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}
SqlDataReader^ Database::LoadStudentCourses(int id) {
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM StudentCourses WHERE StudentID = @id";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}
SqlDataReader^ Database::LoadGrades(int id) {
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM Grades WHERE StudentCourseID = @id";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}
SqlDataReader^ Database::LoadCourse(int id) {
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM Course WHERE CourseID = @id";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}

SqlDataReader^ Database::LoadGradeBreakdown(int id) {
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM GradeBreakdown WHERE GradeID = @id";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}
SqlDataReader^ Database::ExecuteReader(String^ query, array<SqlParameter^>^ parameters) {
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        for each (SqlParameter^ param in parameters) {
            cmd->Parameters->Add(param);
        }
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}
SqlDataReader^ Database::LoadProfessorData(int id) {
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlDataReader^ reader = nullptr;
    try
    {
        conn->Open();
        String^ query = "SELECT * FROM Professor WHERE ProfessorID = @id";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
        return reader;
    }
    catch (Exception^)
    {
        if (conn != nullptr)
            conn->Close();
        return nullptr;
    }
}




