; MAIN STRUCTURE 
INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
    ;VAR/DATA 
     
.CODE
    MAIN PROC
        
        ;WRITE WAHT U WANT TO DO 
   
        
        FINISH:
            MOV AH,4CH
            INT 21H
    ENDP MAIN
    END MAIN
        
        
        