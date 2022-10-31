.include "/home/ra1/m328Pdef.inc"

ldi r16, 0b00111100
out DDRD, r16

ldi r16, 0b00000000

rcall comp

ldi r18, 0b00000010
rcall loopw

out PORTD, r16

Start:
rjmp Start

comp:
ldi r17, 0b00000001
eor r16, r17
ret

loopw:
lsl r16
dec r18
brne loopw
ret	
