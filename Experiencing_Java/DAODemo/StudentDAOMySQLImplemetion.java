import java.io.InputStream;
import java.io.InputStreamReader;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class StudentDAOMySQLImplemetion implements StudentDAO {
    private static Connection connection = null;

    private static PreparedStatement createStm;
    private static PreparedStatement updateStm;
    private static PreparedStatement retriveAllStm;
    private static PreparedStatement retriveByIdStm;
    private static PreparedStatement deleteStm;

    StudentDAOMySQLImplemetion(Connection connection) {
        try {
            connection = connection;
            InputStream ist = getClass().getResourceAsStream("resources/MySQLQuery.properties");
            InputStreamReader fileReader = new InputStreamReader(ist);
            Properties properties = new Properties();
            properties.load(fileReader);

            createStm = connection.prepareStatement(properties.getProperty("INSERT_STUDENT_QUERY"));
            retriveAllStm = connection.prepareStatement(properties.getProperty("RETRIEVE_ALL_STUDENTS_QUERY"));
            retriveByIdStm = connection.prepareStatement(properties.getProperty("RETRIEVE_STUDENT_BY_ID_QUERY"));
            deleteStm = connection.prepareStatement(properties.getProperty("DELETE_ALL_STUDENTS_QUERY"));

        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    @Override
    public Student create(Student student) {

        try {
            createStm.setString(1, student.getId());
            createStm.setString(2,student.getName());
            int executeUpdate = createStm.executeUpdate();
            return retrive(student.getId());
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Student retrive(String studentId) {
        try {
            retriveByIdStm.setString(1, studentId);
            ResultSet resultSet = retriveByIdStm.executeQuery();
            if (resultSet.next()) {
                Student student = new Student(resultSet.getString("id"), resultSet.getString("name"));
                return student;
            }else  return null;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public List<Student> retriveAll() {
        List<Student> studentList = new ArrayList<>();
        ResultSet resultSet = null;
        try {
            resultSet = retriveAllStm.executeQuery();
            while(resultSet.next()){
                studentList.add(new Student(resultSet.getString("id"), resultSet.getString("name")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return studentList;
    }

    @Override
    public List<Student> retrive(Predicate<Student> predicate) {
        return  retriveAll().stream().filter(predicate).collect(Collectors.toList());
    }

    @Override
    public int delteAll() {
        try {
            deleteStm.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return 0;
    }
}
