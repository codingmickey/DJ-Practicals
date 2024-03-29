DATA SEGMENT
   
    STRING1 DB 45H, 0CAH, 65H, 25H ,4CH 
    MAX DB 00H
    MIN DB 0FFH
    
    
DATA ENDS

CODE SEGMENT 
    ASSUME CS:CODE, DS:DATA
   
    START: MOV AX,DATA
    MOV DS,AX
    
   
    MOV CH, 04H
    LEA SI,STRING1
    MOV AL,[SI]
    MOV AH,[SI]
    INC SI
    UP: MOV BL,[SI]
    CMP  AL, BL
    JNC DOWN1
    MOV AL,BL
    DOWN1: CMP AH,BL
    JC DOWN
    MOV AH,BL
    DOWN: INC SI
    DEC CH
    JNZ UP
    
    MOV MAX,AL
    MOV MIN,AH
    

CODE ENDS

END START