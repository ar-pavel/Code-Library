
INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
    ;VAR/DATA 
     
.CODE
    MAIN PROC   
       INPUT: 
           PRINT "INPUT THE FIRST NUMBER  : "
           MOV AH,1  
           INT 21H
           MOV BL,AL
           MOV AH,2
          ; PRINT LINE BREAK AND CARRIAGE RETURN    
           MOV DL,0DH 
           INT 21H
           MOV DL,0AH
           INT 21H

           PRINT "INPUT THE SECOND NUMBER : "
           MOV AH,1
           INT 21H 
           MOV CL,AL           
           ;PRINT LINE BREAK AND CARRIAGE RETURN 
           MOV AH,2
           MOV DL,0AH
           INT 21H
           MOV DL,0DH 
           INT 21H
       
       PRINT:  
           PRINT "THE SUM IS : "
           SUB BL,48
           SUB CL,48
            
           ADD CL,BL 
           
           ADD CL,48
            
           MOV DL,CL
           MOV AH,2
           INT 21H

        
        FINISH:
            MOV AH,4CH
            INT 21H
    ENDP MAIN
    END MAIN
        
        
        