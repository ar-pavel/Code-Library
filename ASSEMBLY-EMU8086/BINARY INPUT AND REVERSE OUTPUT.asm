INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H 

.DATA
    CNT DB 1

.CODE
    MAIN PROC  
        
        MOV AX,@DATA
        MOV DS,AX
        
        MOV BX,0
        MOV AH,1
        
        PRINT " INPUT THE BINARY NUMBER (8BITS MAX) : "
        
        INPUT: 
            INT 21H
            CMP AL,0DH
            JE NXT
            SUB AL,48
            SHL BX,1
            OR BH,AL
            INC CNT
            JMP INPUT
           
        NXT:
            PRINTN
            
            RCR BX,8
            MOV CL,CNT  
            MOV AH,2 
            
            PRINT " THE REVERSE OF THE GIVEN  NUMBER IS : " 
            
        FOR: 
            DEC CX
            RCR BX,1
            JC PRINT1
            
            PRINT "0"
            JMP LAST
            
            PRINT1:
               PRINT "1"
               JMP LAST                
  
        LAST:
             CMP CL,1
             JG FOR   

        FINISH:
            MOV AH,4CH
            INT 21H
    ENDP MAIN
    END MAIN
        