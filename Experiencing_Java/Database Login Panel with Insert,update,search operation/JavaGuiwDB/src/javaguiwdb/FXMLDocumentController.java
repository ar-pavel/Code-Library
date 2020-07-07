package javaguiwdb;

import com.mysql.jdbc.Statement;
import java.net.URL;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TabPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.scene.text.Text;

/**
 *
 * @author ar
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private TabPane operation;
    @FXML
    private TextField Iname;
    @FXML
    private TextArea Iaddress;
    @FXML
    private TextField Iid;
    @FXML
    private Button Isave;
    @FXML
    private TextField Uid;
    @FXML
    private TextArea unAddress;
    @FXML
    private TextField unName;
    @FXML
    private Button Usave;
    @FXML
    private TextField unId;
    @FXML
    private TextField sId;
    @FXML
    private TextArea sResult;
    @FXML
    private Button sReset;
    @FXML
    private AnchorPane welcomePage;
    @FXML
    private TextField userName;
    @FXML
    private Text invalid;
    @FXML
    private PasswordField password;
    @FXML
    private Button login;
    
    private String user = "root";
    private String pass = "";
    private java.sql.Connection con;
    private Statement myStmt;
    
    private String name;
    private String address;
    private int id;
    Alert alert = new Alert(AlertType.INFORMATION);

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        operation.setVisible(false);    
        sReset.setText("Search");
    }    
    
    String query = " insert into man" + " values (?, ?, ?)";
    String uQuery = " UPDATE man SET " + " id = ?, name = ?, address = ? " + " WHERE id = ? ";
    String sQuery = " SELECT * FROM man WHERE " + " id = ? ";
    

    @FXML
    private void insertData(ActionEvent event) {
        name = Iname.getText();
        address = Iaddress.getText();
        id = Integer.valueOf(Iid.getText().trim());
        try {
            try (PreparedStatement preparedStmt = con.prepareStatement(query)) {
                preparedStmt.setInt(1, id);
                preparedStmt.setString(2, name);
                preparedStmt.setString(3,  address);
                preparedStmt.execute();
                // myStmt.executeUpdate("insert into man value("+ id +",'"+  name  +"','"+ address +"')");
            }
        } catch (SQLException ex) {
            Logger.getLogger(FXMLDocumentController.class.getName()).log(Level.SEVERE, null, ex);
        }
        iAlertShow();
    }

    @FXML
    private void updateData(ActionEvent event) throws SQLException {
        id = Integer.parseInt(Uid.getText().trim());
        int uid = Integer.parseInt(unId.getText().trim());
        address = unAddress.getText();
        name = unName.getText();
        int executeUpdate;
        try (PreparedStatement prepareStmt = con.prepareStatement(uQuery)) {
            prepareStmt.setInt(1, uid);
            prepareStmt.setString(2, name);
            prepareStmt.setString(3,address);
            prepareStmt.setInt(4,id);
            prepareStmt.execute();
            //  executeUpdate = myStmt.executeUpdate(" UPDATE man SET " + "id = " + uid + ", name = " + name + ", address = " + address + "WHERE id = " + id);
        }
        alertShow();
    }

    @FXML
    private void resetDisplay(ActionEvent event) throws SQLException {
        id = Integer.parseInt(sId.getText().trim());
        PreparedStatement prepareStmt = con.prepareStatement(sQuery);
        prepareStmt.setInt(1, id);
        ResultSet res = prepareStmt.executeQuery();
         while(res.next()){
             sResult.setText("ID : " + id + "\nName : " + res.getString("\name") + "\nAddress : " +res.getString("address"));
         }
         if("".equals(sResult.getText()))
             sResult.setText("ID not valid");
    }

    @FXML
    private void logIn(ActionEvent event) throws SQLException {        
        if(! userName.getText().trim().equals(user) || !password.getText().trim().equals(pass)){
            invalid.setText("User name or Password is invalid \nTry Again");
            userName.setText("");
            password.setText("");
        }
        else{
            welcomePage.setVisible(false);
            operation.setVisible(true);
            startTheDatabase();
        }
    }

    private void alertShow (){
        alert.setTitle("Information Dialog");
        alert.setHeaderText("Congrats, You have successfully complete the update");
        alert.setContentText("Data updated");
        alert.showAndWait();
        
    }
    private void iAlertShow (){
        alert.setTitle("Information Dialog");
        alert.setHeaderText("Congrats, You have successfully complete the insert");
        alert.setContentText("Data inserted");
        alert.showAndWait();
        
    }
    private void startTheDatabase() throws SQLException {
       con = DriverManager.getConnection("jdbc:mysql://localhost:3306/person", user,pass);
       myStmt = (Statement) con.createStatement();
        
    }
   

    
    
    
}
