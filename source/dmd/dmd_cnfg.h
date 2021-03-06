

#ifndef DMD_CNF_H
#define DMD_CNF_H



#define DISPLAY_HIGH 				2
#define DISPLAY_WIDE				3

#define MAX_X_INDEX					DISPLAY_WIDE * 32 - 1
#define MAX_Y_INDEX					DISPLAY_HIGH * 16 * TOTAL_CONTROLLER - 1

#define CONNECTOR1_OE_PORT 			PORTB
#define CONNECTOR1_OE_PIN			PIN14

#define CONNECTOR1_A_PORT 			PORTB
#define CONNECTOR1_A_PIN			PIN13

#define CONNECTOR1_B_PORT 			PORTB
#define CONNECTOR1_B_PIN			PIN12

#define CONNECTOR1_C_PORT 			PORTB
#define CONNECTOR1_C_PIN			PIN10

#define CONNECTOR1_D_PORT 			PORTB
#define CONNECTOR1_D_PIN			PIN5

#define CONNECTOR1_STROBE_PORT 		PORTB
#define CONNECTOR1_STROBE_PIN		PIN1

#define CONNECTOR1_SCK_PORT 		PORTB
#define CONNECTOR1_SCK_PIN			PIN0





#endif //DMD_CNF_H
