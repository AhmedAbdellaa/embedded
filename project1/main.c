#include <avr/io.h>
#include <util/delay.h>
#define GET_BIT(var,bit_num)  (((var) & (1<<(bit_num)) )?1 :0)
#define SET_BIT(var,bit_num)  ((var) |= (1<<(bit_num)))
#define CLS_BIT(var,bit_num)  ((var) &= ((1<<(bit_num))^-1))

void flashing(){
	_delay_ms(500);
	PORTC=0x00;
	_delay_ms(500);
	PORTC = 0xff;
}
void shiftleft(){

	char i = 0;
	while(i < 8){
		SET_BIT(PORTC,i);
		_delay_ms(250);
		CLS_BIT(PORTC,i);
		i++;
	}
}
void shiftright(){
	char i = 7;
		while(i >0){
			SET_BIT(PORTC,i);
			_delay_ms(250);
			CLS_BIT(PORTC,i);
			i--;
		}

}
void converging(){

	char i = 0;
	//loop
	while(i<4){
		SET_BIT(PORTC,i);
		SET_BIT(PORTC,7-i);
		_delay_ms(300);
		CLS_BIT(PORTC,i);
		CLS_BIT(PORTC,7-i);
		i++;

	}
}
void diverging(){
	signed char i = 3;
	//loop
	while(i>=0){
		SET_BIT(PORTC,i);
		SET_BIT(PORTC,7-i);
		_delay_ms(300);
		CLS_BIT(PORTC,i);
		CLS_BIT(PORTC,7-i);
		i--;
	}

}
void pingpong(){
	shiftleft();
	shiftright();
}
void incrementing(){
	char i = 0;
		//loop
	while(i<8){
		SET_BIT(PORTC,i);
		_delay_ms(300);
		i++;
	}
}
void converging_diverging(){
	converging();
	diverging();
}

void main(){
	//set pins as outputs
	DDRC = 0xff; //port A as output
	PORTC = 0x00; //port a as low

	DDRD = 0x00; //port d as input
	char status0,status1,status2;
	//loop
	while(1){
		//get button status
		status0 = GET_BIT(PIND,2);
		status1 = GET_BIT(PIND,3);
		status2 = GET_BIT(PIND,4);
		//debounsing push button
		_delay_ms(250);
		if (status0 == 0)
			if(status1 == 0){
				if(status2 == 0){
					flashing();//000
				}else{
					shiftleft();//001
				}
			}else{
				if(status2 == 0){
					shiftright();//010
				}else{
					converging();//011
				}
			}
		else
			if(status1 == 0){
				if(status2 == 0){
					diverging();//100
				}else{
					pingpong();//101
				}
			}else{
				if(status2 == 0){
					PORTC = 0x00;
					incrementing();//110
				}else{
					converging_diverging();//111
				}
			}

	}
}
