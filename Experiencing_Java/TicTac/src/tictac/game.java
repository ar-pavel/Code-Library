package tictac;

public class game {
     char[][] table = new char[3][3];

    public void init() {
        for (int i = 0; i < 3; i++) {
            for (int p = 0; p < 3; p++) {
                table[i][p] = ' ';
            }
        }
    }
    
    public boolean checkIfLegal(int row, int column) {     
        return table[row][column] == 'x' || table[row][column] == 'o';
    }

    public boolean checkIfWinner() {
        if (table[0][0] == table[1][0] && table[1][0] == table[2][0] && (table[0][0] == 'x' || table[0][0] == 'o')) 
            return true;
        if (table[0][1] == table[1][1] && table[1][1] == table[2][1] && (table[0][1] == 'x' || table[0][1] == 'o')) 
            return true;
        if (table[0][2] == table[1][2] && table[1][2] == table[2][2] && (table[0][2] == 'x' || table[0][2] == 'o')) 
            return true;
        if (table[0][0] == table[0][1] && table[0][1] == table[0][2] && (table[0][0] == 'x' || table[0][0] == 'o')) 
            return true;
        if (table[1][0] == table[1][1] && table[1][1] == table[1][2] && (table[1][0] == 'x' || table[1][0] == 'o')) 
            return true;
        if (table[2][0] == table[2][1] && table[2][1] == table[2][2] && (table[2][0] == 'x' || table[2][0] == 'o')) 
            return true;
        if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && (table[0][0] == 'x' || table[0][0] == 'o')) 
            return true;
        return table[2][0] == table[1][1] && table[1][1] == table[0][2] && (table[2][0] == 'x' || table[2][0] == 'o');
    }


    public boolean checkIfTie() {
        for (int i = 0; i < 3; i++) {
            for (int p = 0; p < 3; p++) {
                if (table[i][p] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }


}



