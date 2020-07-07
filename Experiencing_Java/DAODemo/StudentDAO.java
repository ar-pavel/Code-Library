
import java.util.List;
import java.util.function.Predicate;

public interface StudentDAO {
    Student create(Student student);
    Student retrive(String studentId);
    List<Student> retriveAll();
    List<Student> retrive(Predicate<Student> predicate);
    int delteAll();

}
