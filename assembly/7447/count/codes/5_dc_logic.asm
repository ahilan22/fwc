.include "/home/ra1/m328Pdef.inc"

ldi r16, 0b00111100
out DDRD, r16 ; set D2-5 as output pins
ldi r17, 0b11001011
;ldi r17, 0b00000000
;out DDRB, r17 ; set D10-13 as input pins
;out PORTB, r17 ; activating pull up 
;in r17, PINB ; read D9-12 into r17 which are w,x,y,z

;pick inputs variables
rcall pickw ; r24
rcall pickx ; r25
rcall picky ; r26
rcall pickz ; r27

ldi r20, 0b00000010
ldi r21, 0b00000011
ldi r22, 0b00000100
ldi r23, 0b00000101

;right shift the variables, r18-21 for conditional
rcall shiftw ; r24
rcall shiftx ; r25 
rcall shifty ; r26
rcall shiftz ; r27

;complement of variables, r28-21
rcall compw
rcall compx
rcall compy
rcall compz

;a,b,c,d calc, r16,17,18,19
mov r16, r28 ; a

mov r17, r24
and r17, r29
and r17, r31
mov r18, r28
and r18, r25
or r17, r18 ; b

mov r18, r24
and r18, r25
and r18, r30
mov r19, r29
and r19, r26
mov r20, r28
and r20, r26
or r18, r19
or r18, r20 ; c

and r24, r25
and r24, r26
and r28, r27
or r24, r28
mov r19, r24 ; d

;shifting left

ldi r20, 0b00000010
ldi r21, 0b00000011
ldi r22, 0b00000100
ldi r23, 0b00000101

rcall shifta
rcall shiftb
rcall shiftc
rcall shiftd

;final required value
add r16, r17
add r16, r18
add r16, r19

out PORTD, r16

Start:
rjmp Start

pickw:
ldi r16, 0b00000100
mov r24, r17
and r24, r16
ret
pickx:
ldi r16, 0b00001000
mov r25, r17
and r25, r16
ret
picky:
ldi r16, 0b00010000
mov r26, r17
and r26, r16
ret
pickz:
ldi r16, 0b00100000
mov r27, r17
and r27, r16
ret

shiftw:
lsr r24
dec r20
brne shiftw
ret
shiftx:
lsr r25
dec r21
brne shiftx
ret
shifty:
lsr r26
dec r22
brne shifty
ret
shiftz:
lsr r27
dec r23
brne shiftz
ret

compw:
ldi r28, 0b00000001
eor r28, r24
ret
compx:
ldi r29, 0b00000001
eor r29, r25
ret
compy:
ldi r30, 0b00000001
eor r30, r26
ret
compz:
ldi r31, 0b00000001
eor r31, r27
ret

shifta:
lsl r16
dec r20
brne shifta
ret
shiftb:
lsl r17
dec r21
brne shiftb
ret
shiftc:
lsl r18
dec r22
brne shiftc
ret
shiftd:
lsl r19
dec r23
brne shiftd
ret
