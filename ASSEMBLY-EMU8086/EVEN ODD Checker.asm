INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA 

.CODE
    MAIN PROC   
       
        @INPUT:            
            PRINT " INPUT THE NUMBER : "
            MOV AH,1
            INT 21H  
              
        @CHECK: 
            MOV AH,0
            MOV DL, 2
            DIV DL
            
            CMP AH,0
            JE @EVEN

            
        @ODD: 
            MOV AH,2
            MOV DL,0AH
            INT 21H  
            MOV DL,0DH
            INT 21H
               
            PRINT " THE NUMBER IS ODD " 
            JMP FINISH  
                
        @EVEN:  
            MOV AH,2
            MOV DL,0AH
            INT 21H  
            MOV DL,0DH
            INT 21H
              
            PRINT " THE NUMBER IS EVEN " 
           
        FINISH:
            MOV AH,4CH
            INT 21H
    ENDP MAIN
    END MAIN    
