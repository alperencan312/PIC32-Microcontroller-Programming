###########################################################################

PRELIMINARY PART C

###########################################################################

// This code shows and rotates the pattern (10001000) right or stops based on the input coming from the user. The pattern is to be shown on the LEDs.
int stop = 0;
int initial = 0b10001000; //Initial pattern. Note that 0 means on, while 1 means off.
int right = 1;
int DIR = 0;
int EN = 1;
void main(){
     TRISD = 0x0; // All bits of PORTD are output. ~0 means output~
     // Three bits of PORTA are inputs
     TRISA = 0b111;
     // From PORTD, outputs will be sent to LEDs.
     // Initial pattern is sent to the LEDs through PORTD.
     PORTD = initial;
     while(1){
              if( DIR == 0 && EN == 1 )
              {
                  int lsb; // least significant bit
                  int mask;
                  // Stop button is the push-button which is labeled as 1 on the board.
                  if(PORTABits.RA1 == 0){ // If stop button clicked
                               stop = !stop;
                               if(!stop){
                               // If process restarted, copy initial pattern into PORTD.
                               PORTD = initial;
                               }
                  }
                  if(!stop){
                        //Rotate right
                       lsb = PORTD & 0x1; // Extract least significant bit
                       mask = lsb << 7; // Least significant bit will be the msb of the shifted pattern
                       PORTD = (PORTD >> 1) | mask; // Paste lsb to the leftmost bit the right shifted portd
                  }  else {
                     //Do not shift anything, that is, stop.
                     PORTD = 0b11111111;
                  }
               }
               else if( DIR == 1 && EN ==1 )
              {
                  int msb;
                  int mask;
                  // Stop button is the push-button which is labeled as 1 on the board.
                  if(PORTABits.RA1 == 0){ // If stop button clicked
                               stop = !stop;
                               if(!stop){
                               // If process restarted, copy initial pattern into PORTD.
                               PORTD = initial;
                               }
                  }
                  if(!stop){
                        //Rotate left
                       msb = PORTD & 0b10000000; // Extract most significant bit
                       mask = msb >> 7; // Most significant bit will be the lsb of the shifted pattern
                       PORTD = (PORTD << 1) | mask; // Paste msb to the rightmost bit the left shifted portd
                  }  else {
                     //Do not shift anything, that is, stop.
                     PORTD = 0b11111111;
                  }
               }
               else if( EN == 0 )
               {
                     PORTD = PORTD; // If EN equals to zero, the position is "frozen"
               }
               if( PORTABits.RA2 == 0 ) {
                     DIR = !DIR;	// DIR button is the push button which is labeled as 2 on the board.
               }
               if( PORTABits.RA3 == 0 ) {
                       EN = !EN;	// EN button is the push button which is labeled as 3 on the board.
               }
              delay_ms(1000); // Wait 1 second.
     }
}
// Rotation ends here



###########################################################################

PRELIMINARY PART D

###########################################################################

int x = 1;
int value = 1;	// value is f(x)
int first;	// rightmost digit of f(x)
int second;	// second rightmost digit of f(x)
int third;	// third rightmost digit of f(x)
int fourth;	// leftmost digit of f(x)
int increment; 	// counter for the loop
void main() {

     TRISD = 0x0; // All bits of PORTB are output. ~0 means output~
     TRISE = 0x0; // All bits of PORTB are output. ~0 means output~
     // From PORTD, outputs will be sent to 7 Segment.
     while(1){
              //Display
              first = value % 10;	// takes the rightmost digit
              value = value /10;
              second = value % 10;	// takes the second rightmost digit
              value = value /10;
              third = value % 10;	// takes the third rightmost digit
              value  = value /10;
              fourth = value %10;	// takes the leftmost digit

	      // Since there are four 1ms delays among following switch statements, it should loop 250 times in order to delay a total of 1 second between f(x) values.

              for( increment = 0; increment< 250; increment++ )
              {
                   switch( first ){	// Following case statements display the digit at 7-Segment
                   case 0:   PORTD  =   0x3F; break;
                   case 1:   PORTD  =   0x06; break;
                   case 2:   PORTD  =   0x5B; break;
                   case 3:   PORTD  =   0x4F; break;
                   case 4:   PORTD  =   0x66; break;
                   case 5:   PORTD  =   0x6D; break;
                   case 6:   PORTD =   0x7D; break;
                   case 7:   PORTD  =  0x07; break;
                   case 8:   PORTD  = 0x7F; break;
                   case 9:   PORTD = 0x6F; break;
                   default:   0x00; break;
                   }
                   PORTE = 0x8;
                   delay_ms(1);
                   switch( second ){	// Following case statements display the digit at 7-Segment
                   case 0:   PORTD  =   0x3F; break;
                   case 1:   PORTD  =   0x06; break;
                   case 2:   PORTD  =   0x5B; break;
                   case 3:   PORTD  =   0x4F; break;
                   case 4:   PORTD  =   0x66; break;
                   case 5:   PORTD  =   0x6D; break;
                   case 6:   PORTD =   0x7D; break;
                   case 7:   PORTD  =  0x07; break;
                   case 8:   PORTD  = 0x7F; break;
                   case 9:   PORTD = 0x6F; break;
                   default:   0x00; break;
                   }
                   PORTE = 0x4;
                   delay_ms(1);
                    switch( third ){	// Following case statements display the digit at 7-Segment
                    case 0:   PORTD  =   0x3F; break;
                    case 1:   PORTD  =   0x06; break;
                    case 2:   PORTD  =   0x5B; break;
                    case 3:   PORTD  =   0x4F; break;
                    case 4:   PORTD  =   0x66; break;
                    case 5:   PORTD  =   0x6D; break;
                    case 6:   PORTD =   0x7D; break;
                    case 7:   PORTD  =  0x07; break;
                    case 8:   PORTD  = 0x7F; break;
                    case 9:   PORTD = 0x6F; break;
                    default:   0x00; break;
                    }
                    PORTE = 0x2;
                    delay_ms(1);
                    switch( fourth ){	// Following case statements display the digit at 7-Segment
                    case 0:   PORTD  =   0x3F; break;
                    case 1:   PORTD  =   0x06; break;
                    case 2:   PORTD  =   0x5B; break;
                    case 3:   PORTD  =   0x4F; break;
                    case 4:   PORTD  =   0x66; break;
                    case 5:   PORTD  =   0x6D; break;
                    case 6:   PORTD =   0x7D; break;
                    case 7:   PORTD  =  0x07; break;
                    case 8:   PORTD  = 0x7F; break;
                    case 9:   PORTD = 0x6F; break;
                    default:   0x00; break;
                    }
                    PORTE = 0x1;
                    delay_ms(1);
              }
              //return to one if the limit is reached
              if( x == 21 )
              {
                  x = 1;
                  value = 1;
              }
              else
              {
                  x = (x+1);		// increment x
                  value = x*x*x;	// take its cube
              }
     }
}
