package tictac;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.text.Font;

/**
 * @author ar
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private Button button1;
    @FXML
    private Font x1;
    @FXML
    private Button button4;
    @FXML
    private Button button7;
    @FXML
    private Button button2;
    @FXML
    private Button button3;
    @FXML
    private Button button5;
    @FXML
    private Button button6;
    @FXML
    private Button button8;
    @FXML
    private Button button9;
    @FXML
    private Label O;
    @FXML
    private Label x;
    @FXML
    private Label t5;
    @FXML
    private Label X;
    @FXML
    private Label o;

    private boolean chkTrn = false;
    private boolean opt = false;

    private char trn = 'x';

    private game g = new game();    
    private int wx = 0;
    private int wo = 0;

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        g.init();
    }

    @FXML
    private void change(ActionEvent event) {
        if (chkTrn) {
            cleanup();
        }

        Button but = (Button) event.getSource();

        if (but == button1 && !g.checkIfLegal(0, 0)) {
            g.table[0][0] = trn;
        } else if (but == button2 && !g.checkIfLegal(0, 1)) {
            g.table[0][1] = trn;
        } else if (but == button3 && !g.checkIfLegal(0, 2)) {
            g.table[0][2] = trn;
        } else if (but == button4 && !g.checkIfLegal(1, 0)) {
            g.table[1][0] = trn;
        } else if (but == button5 && !g.checkIfLegal(1, 1)) {
            g.table[1][1] = trn;
        } else if (but == button6 && !g.checkIfLegal(1, 2)) {
            g.table[1][2] = trn;
        } else if (but == button7 && !g.checkIfLegal(2, 0)) {
            g.table[2][0] = trn;
        } else if (but == button8 && !g.checkIfLegal(2, 1)) {
            g.table[2][1] = trn;
        } else if (but == button9 && !g.checkIfLegal(2, 2)) {
            g.table[2][2] = trn;
        } else {
            t5.setText(t5.getText() + "\nInvalid");
            return;
        }

        changeTurn(but);
        
        if (g.checkIfTie()) {
            chkTrn = true;
            t5.setText("Game is TIE");
        }

    }

    private void cleanup() {
        g.init();
        button1.setText("");
        button2.setText("");
        button3.setText("");
        button4.setText("");
        button5.setText("");
        button6.setText("");
        button7.setText("");
        button8.setText("");
        button9.setText("");
        if (opt) {
            t5.setText("It's X's turn");
        } else {
            t5.setText("It's O's turn");
        }
        opt = (opt)? !opt : opt;
        chkTrn = false;
    }

    private void changeTurn(Button but) {
        if (trn == 'x') {
            but.setText("X");
            trn = 'o';
            t5.setText("It's O's turn");
            if (g.checkIfWinner()) {
                t5.setText("X win");
                wx++;
                chkTrn = true;
                X.setText(Integer.toString(wx));
            }
        } else {
            but.setText("O");
            trn = 'x';
            t5.setText("It's X's turn");
            if (g.checkIfWinner()) {
                t5.setText("O win");
                wo++;
                chkTrn = true;
                O.setText(Integer.toString(wo));
            }

        }
    }

}
