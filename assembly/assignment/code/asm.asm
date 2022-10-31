.include "/root/m328Pdef.inc"

ldi r16, 0x20; set D8,9-inputs, D13-output
out DDRB, r16
ldi r16, 0x00; internal pullup 
out PORTB, r16
in r16, PINB ; read inputs A=8 and B=9

Start:

ldi r17, 0x01; mask to get A
mov r18, r16
and r18, r17 ; A
lsr r16
and r16, r17 ; B
mov r19, r18 
com r19      ; A_comp
mov r20, r16 
com r20      ; B_comp

and r19, r20
and r16, r18
or r16, r19  ; Y*

ldi r17, 0x05
rcall shifty ; Y
out PORTB, r16

rjmp Start

shifty:
lsl r16
dec r17
brne shifty
ret
