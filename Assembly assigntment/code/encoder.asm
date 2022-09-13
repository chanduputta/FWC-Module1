.include "/home/shreyash/m328Pdef.inc"

;Configuring pin 13 (PB5)
  ldi r16,0b00100000
  out DDRB,r16
;Configuring pins 4 (PD4) of Arduino
;as output
  ldi r16,0b00010000
  out DDRD,r16
  
  
ldi r17,0b00000001   ;D0
ldi r18,0b00000000   ;D1
ldi r19,0b00000000   ;D2
ldi r20,0b00000000   ;D3


;ldi r15,0b00000001  ; used for compliment ; if required

;for Q0 (R22)

mov r22,r18
or r22,r20 ; Q0 = d1 || d3
lsl r22
lsl r22
lsl r22
lsl r22
lsl r22
out PortB,r22 ; PB5

;for Q1 (R23)

mov r23,r19
or r23,r20 ; Q1 = d2 || d3
lsl r23
lsl r23
lsl r23
lsl r23
out PortD,r23 ; PD4

;output on PORTB
;or r22,r23
;;out PORTD,r22


Start:
rjmp Start
