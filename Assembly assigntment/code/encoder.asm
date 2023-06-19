; Code by Shreyash Chandra
; August, 2022
; under FWC program by IITH
; Design 4x2 encoder 

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
ldi r25,0x9c
;;;;;loop1;;;;;;;
clr r25
l1:
cpi r25,5   ; comparing r25 to 5
breq next   ; break and goto next
lsl r22
inc r25
rjmp l1
;;;;;;loop1;;;;;;;;;;;;
next:
out PortB,r22 ; PB5

;for Q1 (R23)

mov r23,r19
or r23,r20 ; Q1 = d2 || d3

clr r25  ; r25 == 0
;;;;;;;loop2;;;;;

l2:
cpi r25,4
breq next1   ; break and goto next1
lsl r23
inc r25
rjmp l2     
;;;;;;;loop2;;;;;;;
next1:
out PortD,r23 ; PD4

;output on PORTB
;or r22,r23
;;out PORTD,r22


Start:
rjmp Start
;comment
