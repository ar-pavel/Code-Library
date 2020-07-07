import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.RandomAccess;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class StudentDAOFileImplementation implements StudentDAO {

    public StudentDAOFileImplementation() {

    }

    @Override
    public Student create(Student student) {
        try {
            RandomAccessFile input = new RandomAccessFile("StudentFileImplementation.txt", "rw");
            input.seek(input.length());
            input.writeUTF(student.getId());
//            input.writeUTF(" ");
            input.writeUTF(student.getName());
//            input.writeUTF("\");
            input.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return null;
    }

    @Override
    public Student retrive(String studentId) {
        List<Student>studentList = retriveAll();
        return studentList.stream().filter(s -> s.getId().equals(studentId)).findAny().orElse(null);
    }

    @Override
    public List<Student> retriveAll() {
        List<Student>studentList = new ArrayList<>();
        try {
            RandomAccessFile input = new RandomAccessFile("StudentFileImplementation.txt", "r");
            String line;
            while((line = input.readLine()) != null){
                String id = line.split("\\;")[0];
                String name = line.split("\\;")[1];
                studentList.add(new Student(id, name));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return studentList;
    }

    @Override
    public List<Student> retrive(Predicate<Student> predicate) {
       return retriveAll().stream().filter(predicate).collect(Collectors.toList());
    }

    @Override
    public int delteAll() {
        try {
            PrintWriter writer = new PrintWriter("StudentFileImplementation.txt","UTF-8");
            writer.flush();
            writer.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        return 0;
    }
}
