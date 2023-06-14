#ifndef UART_REG
#define UART_REG

#define UDR     *((volatile uint8*)0x2C)

#define UCSRA   *((volatile uint8*)0x2B)
#define UCSRA_RXC  7U
#define UCSRA_UDRE  5U
#define UCSRB   *((volatile uint8*)0x2A)
#define UCSRB_RXEN  4U
#define UCSRB_TXEN  3U
#define UCSRC   *((volatile uint8*)0x40)

#define UCSRC_URSEL   7U
#define UCSRC_UMSEL   6U
#define UCSRC_UPM1    5U
#define UCSRC_UPM0    4U
#define UCSRC_USBS    3U
#define UCSRC_UCSZ1    2U
#define UCSRC_UCSZ0    1U
#define UCSRC_UCPOL   0U

#define UBRRH   *((volatile uint8*)0x40)
#define UBRRL   *((volatile uint8*)0x29)

#endif
