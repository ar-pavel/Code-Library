INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
.CODE
    MAIN PROC  
        START: 
            MOV AH,1
            INT 21H
            
            MOV BL,AL 
                        
            MOV AH,2
            MOV DL,0AH
            INT 21H
            
            MOV DL,0DH
            INT 21H   
        CMPz:
            CMP BL,'z'
            JG ERR               
        CMPa:
            CMP BL,'a'
            JGE PRINT1   
        CMPGZ: 
            CMP BL,'Z'
            JG  ERR   
           
        CMPGA: 
            CMP BL,'A'
            JGE  PRINT2
            
        ERR:
            PRINT "INVALID INPUT"
            JMP FINISH
       
       PRINT1:                                
            PRINT "THE INPUT "  
            MOV AH,2
            MOV DL,BL
            INT 21H
            PRINTN " IS A LOWER CASE LETTER"  
            JMP FINISH   
                           
       PRINT2:                                
            PRINT "THE INPUT "  
            MOV AH,2
            MOV DL,BL
            INT 21H
            PRINTN " IS A UPER CASE LETTER"          
            
        FINISH: 
            MOV AH, 4CH
            INT 21H
        MAIN ENDP
    END MAIN