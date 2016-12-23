#!/usr/bin/python3


import re
import string
import sys


# Opening input file
ipFile = input("Enter file name: ")
ifptr = open(ipFile, 'r')
ifptr.seek(0)

# Storing register details
symbolTable = {}
LC = 0
reg8 = {
            'AL':'000',
            'CL':'001',
            'DL':'010',
            'BL':'011',
            'AH':'100',
            'CH':'101',
            'DH':'110',
            'BH':'111'
        }
reg16 = {
            'AX':'000',
            'CX':'001',
            'DX':'010',
            'BX':'011',
            'SP':'100',
            'BP':'101',
            'SI':'110',
            'DI':'111'
         }  


def addressString(loc, n):                                 #Generates the memory map
    contStr = hex(loc)[2:].zfill(n)
    ba = bytearray.fromhex(contStr)
    li = list(ba)
    s = ""
    for i in li:
        s += hex(i)[2:].zfill(2) + " "
    s = s[:-1]
    return s

    
def byteString(instr, op1, size, op2 = ''):                #Generates the desired opcode
    binStr = ""
    if instr == 'MOV':
        
        binStr += "1000101"
        if op1 in ['AL', 'CL', 'DL', 'BL', 'AH', 'CH', 'DH', 'BH']:
            binStr += "0" + "11" + reg8[op1] + reg8[op2]
        elif op1 in ['AX', 'CX', 'DX', 'BX', 'SP', 'BP', 'SI', 'DI']:
            
            if op2 in ['AX', 'CX', 'DX', 'BX', 'SP', 'BP', 'SI', 'DI']:
                binStr += "1" +  "11" + reg16[op1] + reg16[op2]
            else:
                binStr = "11000111" + "11" + reg16[op1] + bin(int(op2[2:4], 16))[2:] + bin(int(op2[0:2], 16))[2:]
    
    elif instr == 'ADD':
        binStr += "00000001" + "11" + reg16[op1] + reg16[op2]
    elif instr == 'JZ':
        binStr += "01110100"
        addr = symbolTable[op1]
        disp = int(addr) - op2
        if disp >= 0:
            addr = disp
        else:
            addr = 0xff + disp + 1
        addr = hex(addr)[2:]
        addr = addr.zfill(2)
        byte1 = int(addr, 16)
        byte1 = bin(byte1)[2:].zfill(8)
        binStr += byte1
    return addressString(int(binStr, 2), size)

# Pass 1
for line in ifptr:       
    #MOV 8-BIT REG, REG (2B)
    m = re.match('([A-Z0-9]*) ?MOV (AL|CL|DL|BL|AH|CH|DH|BH), (AL|CL|DL|BL|AH|CH|DH|BH)', line)
    if m:
        label = m.group(1)
        if label != '':
            symbolTable[label] = LC
        LC += 2
        
    #MOV 16-BIT REG, REG (2B)
    m = re.match('([A-Z0-9]*) ?MOV (AX|CX|DX|BX|SP|BP|SI|DI), (AX|CX|DX|BX|SP|BP|SI|DI)', line)
    if m:
        label = m.group(1)
        if label != '':
            symbolTable[label] = LC
        LC += 2
        
    #MOV 16-BIT REG, 16-BIT DATA (4B)
    m = re.match('([A-Z0-9]*) ?MOV (AX|CX|DX|BX|SP|BP|SI|DI), [A-F0-9]{4}', line)
    if m:
        label = m.group(1)
        if label != '':
            symbolTable[label] = LC
        LC += 4
    
    #ADD 16-BIT REG, REG (2B)
    m = re.match('([A-Z0-9]*) ?ADD (AX|CX|DX|BX|SP|BP|SI|DI), (AX|CX|DX|BX|SP|BP|SI|DI)', line)
    if m:
        label = m.group(1)
        if label != '':
            symbolTable[label] = LC
        LC += 2
    
    #JZ LABEL (2B)
    m = re.match('([A-Z0-9]*) ?JZ [A-Z0-9]+', line)
    if m:
        label = m.group(1)
        if label != '':
            symbolTable[label] = LC
        LC += 2
        
ifptr.seek(0)
LC = 0
    
# Pass 2


opFile = input("Enter output file name: ")
ofptr = open(opFile, 'w')
ofptr.seek(0)

for line in ifptr:
    #MOV 8-BIT REG, REG (2B)
    m = re.match('([A-Z0-9]*) ?MOV (AL|CL|DL|BL|AH|CH|DH|BH), (AL|CL|DL|BL|AH|CH|DH|BH)', line)
    if m:
        label = m.group(1)
        op1 = m.group(2)
        op2 = m.group(3)
        ofptr.write(addressString(LC, 4) + ": " + byteString('MOV', op1, 4, op2) + "\n")
        LC += 2
        
    #MOV 16-BIT REG, REG (2B)
    m = re.match('([A-Z0-9]*) ?MOV (AX|CX|DX|BX|SP|BP|SI|DI), (AX|CX|DX|BX|SP|BP|SI|DI)', line)
    if m:
        label = m.group(1)
        op1 = m.group(2)
        op2 = m.group(3)
        ofptr.write(addressString(LC, 4) + ": " + byteString('MOV', op1, 4, op2) + "\n")
        LC += 2
        
    #MOV 16-BIT REG, 16-BIT DATA (4B)
    m = re.match('([A-Z0-9]*) ?MOV (AX|CX|DX|BX|SP|BP|SI|DI), ([A-F0-9]{4})', line)
    if m:
        label = m.group(1)
        op1 = m.group(2)
        op2 = m.group(3)
        ofptr.write(addressString(LC, 4) + ": " + byteString('MOV', op1, 8, op2) + "\n")
        LC += 4
    
    #ADD 16-BIT REG, REG (2B)
    m = re.match('([A-Z0-9]*) ?ADD (AX|CX|DX|BX|SP|BP|SI|DI), (AX|CX|DX|BX|SP|BP|SI|DI)', line)
    if m:
        label = m.group(1)
        op1 = m.group(2)
        op2 = m.group(3)
        ofptr.write(addressString(LC, 4) + ": " + byteString('ADD', op1, 4, op2) + "\n")
        LC += 2
    
    #JZ LABEL (3B)
    m = re.match('([A-Z0-9]*) ?JZ ([A-Z0-9]+)', line)
    if m:
        label = m.group(1)
        address = m.group(2)
        tmp = LC
        LC += 2
        ofptr.write(addressString(tmp, 4) + ": " +  byteString('JZ', address, 4, LC) + "\n")
 
ifptr.close()
ofptr.close()
print("Assembly successful. Output file is '" + opFile + "'")