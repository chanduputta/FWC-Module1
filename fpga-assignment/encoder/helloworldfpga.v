/*Program for 4to2 encoder
novenber 2,2022
Code by Shreyash
Released under GNU GPL
*/

//declaring the IO module
module helloworldfpga(

input  wire X,
input  wire Y,
input  wire Z,
input  wire W,


output wire A,
output wire B

);


//Display Decoder
always @(*)
begin


A= X||Z;
B= Y||Z;



end
endmodule

//end of the module




