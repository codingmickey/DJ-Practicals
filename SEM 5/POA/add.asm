MOV AX, 9401H
MOV CL, 00H 

SUB AX, 9002H
JNC jump
            
INC CL


jump: 
    MOV [1004H], AX    
    MOV [1006H], CL

