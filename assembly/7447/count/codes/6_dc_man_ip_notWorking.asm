.include "/home/ra1/m328Pdef.inc"

ldi r16, 0b00111100
out DDRD, r16 ; set D2-5 as output pins
ldi r17, 0x00
out DDRB, r17 ; set D8-11 as input pins
ldi r17, 0x00
out PORTB, r17 ; internal pull up 
in r17, PINB ; read D8-11 into r17 which are w,x,y,z

Start:

;pick inputs variables
rcall pickw ; r24
rcall pickx ; r25
rcall picky ; r26
rcall pickz ; r27

;shift counters
ldi r21, 0x01
ldi r22, 0x02
ldi r23, 0x03

;right shift the variables
	     ; r24,w
rcall shiftx ; r25,x
rcall shifty ; r26,y
rcall shiftz ; r27,z

;complement of variables, r28-31
mov r28, r24 ; r28,w_comp
com r28
mov r29, r25 ; r29,x_comp
com r29
mov r30, r26 ; r30,y_comp
com r30
mov r31, r27 ; r31,z_comp
com r31

;a,b,c,d calc, r16,17,18,19
mov r16, r28 ; a

mov r17, r24
and r17, r29
and r17, r31 ; wx'z'
mov r18, r28
and r18, r25 ; w'x
or r17, r18  ; b

mov r18, r24
and r18, r25
and r18, r30 ; wxy'
mov r19, r29
and r19, r26 ; x'y
mov r20, r28
and r20, r26 ; w'y
or r18, r19
or r18, r20  ; c

and r24, r25 
and r24, r26 ; wxy
and r28, r27 ; w'z
or r24, r28
mov r19, r24 ; d

;left shift counters
ldi r20, 0x02
ldi r21, 0x03
ldi r22, 0x04
ldi r23, 0x05

;shifting left
rcall shifta
rcall shiftb
rcall shiftc
rcall shiftd

;final required value
add r16, r17
add r16, r18
add r16, r19

out PORTD, r16

rjmp Start

; ****subroutine-1****

pickw:
ldi r16, 0x01
mov r24, r17
and r24, r16
ret
pickx:
ldi r16, 0x02
mov r25, r17
and r25, r16
ret
picky:
ldi r16, 0x04
mov r26, r17
and r26, r16
ret
pickz:
ldi r16, 0x08
mov r27, r17
and r27, r16
ret

; ****subroutine-2****

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

; ****subroutine-3****

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
