DATA SEGMENT
   
   FACT DB 5
   RESULT DB ?
    
    
DATA ENDS

CODE SEGMENT 
    ASSUME CS:CODE, DS:DATA
   
    START: MOV AX,DATA
    MOV DS,AX
 
    
    MOV AH,00   
    MOV AL,FACT
    UP: DEC FACT
    MUL FACT
    MOV CL,FACT
    CMP CL,01
    JNZ UP
    
    MOV RESULT,AL 
    

CODE ENDS

END START
