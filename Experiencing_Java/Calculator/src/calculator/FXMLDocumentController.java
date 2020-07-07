package calculator;

import static java.lang.Double.parseDouble;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Tooltip;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import static oracle.jrockit.jfr.events.Bits.intValue;

/**
 * FXML Controller class
 *
 * @author ar
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private Button s4;
    @FXML
    private Color x2;
    @FXML
    private Font x1;
    @FXML
    private Insets x3;
    @FXML
    private Button s9;
    @FXML
    private Button sub;
    @FXML
    private Button s6;
    @FXML
    private Button multiply;
    @FXML
    private Button s1;
    @FXML
    private Button s3;
    @FXML
    private Button divide;
    @FXML
    private Button point;
    @FXML
    private Button equal;
    @FXML
    private Button add;
    @FXML
    private Button s7;
    @FXML
    private Button s8;
    @FXML
    private Button s5;
    @FXML
    private Button s2;
    @FXML
    private Button s0;
    @FXML
    private Button clear;
    @FXML
    private Color x4;
    @FXML
    private Button backSpace;
    @FXML
    private Button square;
    @FXML
    private Button sqrt;
    @FXML
    Tooltip tp1 = new Tooltip("Do");
    
    private String preText = "";
    private String posText = "";
    private String operation = "";
    private double value;
    private double value1;
    boolean cl = true;
    
    @FXML
    private TextField display;
    

    /**
     * Initializes the controller class.
     * @param url
     * @param rb
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        //s1.setTooltip(tp1);
    }    
    
    private boolean isInt(Double value){
        int val = intValue(value);
        return (value==val);
    }        
        
    @FXML
    private void updateDisplay(ActionEvent event) {
        if(!cl){
            preText = "";
            cl =true;
        }
        String textNow = ((Button)event.getSource()).getText();
        if(".".equals(textNow) || preText.contains("."))
           point.setDisable(true);
        textNow = preText + textNow;
        display.setText(textNow);
        preText = textNow;
    }
    

    @FXML
    private void operations(ActionEvent event) {
        display.setText("");
        posText = preText;
        preText = "";
        if(!preText.contains("."))
            point.setDisable(false);
        operation = ((Button)event.getSource()).getText();
       
    }

    @FXML
    private void makeOpetation(ActionEvent event) {
        cl = false;
        if(!posText.contains("."))
              point.setDisable(false);
        switch(operation){
            case "+":
                doAddition();
                break;
            case "-":
                doSubstraction();
                break;
            case "x":
                doMultiplication();
                break;
            case "*":
                doMultiplication();
                break;
            case "/":
                doDivision();
                break;                                         
        }
    }

    @FXML
    private void ClearAll(ActionEvent event) {
        point.setDisable(false);
        preText = "";
        posText = "";
        display.setText("");
    }

    @FXML
    private void square(ActionEvent event) {
        value = parseDouble(preText);
        value = value*value;
        if(isInt(value))         
            preText =  intValue(value)+"";
        else 
            preText = value+"";
        display.setText(preText);
    }

    @FXML
    private void squareRoot(ActionEvent event) {
        value = parseDouble(preText);
        value = Math.sqrt(value);
        preText = value+"";
        display.setText(preText);
    }

    private void doAddition() {
        value = parseDouble(preText);
        value1 = parseDouble(posText);
        value =  value+value1;
        if(isInt(value))         
            preText =  intValue(value)+"";
        else 
            preText = value+"";
        display.setText(preText);
    }

    private void doSubstraction() {
        value = parseDouble(preText);
        value1 = parseDouble(posText);    
        value = value-value1;
         if(isInt(value))         
            preText =  intValue(value)+"";
        else 
            preText = value+"";
        display.setText(preText);
    }

    private void doMultiplication() {
        value = parseDouble(preText);
        value1 = parseDouble(posText);
        value = value*value1;
         if(isInt(value))         
            preText =  intValue(value)+"";
        else 
            preText = value+"";
        display.setText(preText);
    }

    private void doDivision() {
        value = parseDouble(preText);
        value1 = parseDouble(posText);
        value = value1/value;
         if(isInt(value))         
            preText =  intValue(value)+"";
        else 
            preText = value+"";
        display.setText(preText);
    }

    @FXML
    private void delete(ActionEvent event) {
        preText = preText.substring(1);
        display.setText(preText);        
    }       
}