INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA 
    NUM1 DB ?
    NUM2 DB ?   
     
.CODE
    MAIN PROC   
        @LOAD_DATA: 
            MOV AX,@DATA
            MOV DS,AX   
            MOV DS,AX   
        
        @INPUT:            
            PRINT " INPUT 1ST NUMBER : "
            MOV AH,1
            INT 21H  
            SUB AL,30H
            MOV NUM1,AL
            
            MOV AH,2
            MOV DL,0AH
            INT 21H  
            MOV DL,0DH
            INT 21H
            
            PRINT " INPUT ANOTHER NUMBER : "
            MOV AH,1
            INT 21H
            SUB AL,30H
            MOV NUM2,AL
            MUL NUM1  
            
        @MULTIPLICATION:  
            AAM     ;ASCII ADJUST AFER MULTIPLICATION   
            ADD AH,30H
            ADD AL,30H
            MOV BX,AX
            
            MOV AH,2
            MOV DL,0AH
            INT 21H
            MOV DL,0DH
            INT 21H
           
        @RESULT:    
            PRINT " THE RESULT IS : " 
            MOV AH,2
            MOV DL,BH
            INT 21H
            MOV AH,2
            MOV DL,BL
            INT 21H
        
        
        FINISH:
            MOV AH,4CH
            INT 21H
    ENDP MAIN
    END MAIN    
