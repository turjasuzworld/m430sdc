//----------------------------------------------------------------------------
//  This include file contains definitions specific to the hardware board.
//----------------------------------------------------------------------------
// ********************************************************
//
//   
//
//            MSP430F169                  MMC Card 
//         -----------------          -----------------
//     /|\|              XIN|-   /|\ |                 |
//      | |                 |     |  |                 |
//      --|RST          XOUT|-    |--|Pin4/Vcc         |
//        |                 |        |                 |
//        |                 |        |                 |
//        |            P5.6 |<-------|Pin6/CD          |
//        |            P5.0 |------->|Pin1/CS          |
//        |                 |        |                 |
//        |      P5.2/SOMI1 |------->|Pin7/DOUT        |
//        |      P5.1/SIMO1 |<-------|Pin2/DIN         |
//        |      P5.3/UCLK1 |------->|Pin5/CLK         |
//        |                 |        |                 |
//        |                 |     |--|Pin3/GND         |
//                                |
//                                =
//
//  Pin configuration at MSP430F169:
//  --------------------------------
//  MSP430F169      MSP Pin        MMC             MMC Pin
//  -------------------------------------------------------------
//  P5.0              48           ChipSelect       1
//  P5.2 / SOMI       46           DataOut          7
//                                 GND              3 (0 V)
//                                 VDD              4 (3.3 V)
//  P5.3 / UCLK1      47           Clock            5
//  P5.6              44           CardDetect       6
//  P5.1 / SIMO       45           DataIn           2
//  -------------------------------------------------------------



#include "msp430.h"              // Adjust this according to the
                                     // MSP430 device being used.
// SPI port definitions              // Adjust the values for the chosen
#define SPI_PxSEL         P5SEL      // interfaces, according to the pin
#define SPI_PxxSEL        P3SEL
#define SPI_PxDIR         P5DIR      // assignments indicated in the
#define SPI_PxxDIR        P3DIR      // assignments indicated in the
#define SPI_PxIN          P5IN       // chosen MSP430 device datasheet.
#define SPI_PxxIN         P3IN
#define SPI_PxOUT         P5OUT
#define SPI_PxxOUT        P3OUT
#define SPI_SIMO          BIT7  //P3.7
#define SPI_SOMI          BIT4  //P5.4
#define SPI_UCLK          BIT5  //P5.5

//----------------------------------------------------------------------------
// SPI/UART port selections.  Select which port will be used for the interface 
//----------------------------------------------------------------------------
//#define SPI_SER_INTF      SER_INTF_USART1  // Interface to MMC
#define SPI_SER_INTF      SER_INTF_USCIB1//SER_INTF_BITBANG  // Interface to MMC


/*

#include "msp430x47x4.h"            // Adjust this according to the
                                     // MSP430 device being used.
// SPI port definitions              // Adjust the values for the chosen
#define SPI_PxSEL         P3SEL      // interfaces, according to the pin
#define SPI_PxDIR         P3DIR      // assignments indicated in the
#define SPI_PxIN          P3IN       // chosen MSP430 device datasheet.
#define SPI_PxOUT         P3OUT
#define SPI_SIMO          0x02
#define SPI_SOMI          0x04
#define SPI_UCLK          0x08

//----------------------------------------------------------------------------
// SPI/UART port selections.  Select which port will be used for the interface 
//----------------------------------------------------------------------------
#define SPI_SER_INTF      SER_INTF_USCIB0  // Interface to MMC
*/



// SPI port definitions              // Adjust the values for the chosen
#define MMC_PxSEL         SPI_PxSEL      // interfaces, according to the pin
#define MMC_PxxSEL        SPI_PxxSEL
#define MMC_PxDIR         SPI_PxDIR      // assignments indicated in the
#define MMC_PxxDIR        SPI_PxxDIR
#define MMC_PxIN          SPI_PxIN       // chosen MSP430 device datasheet.
#define MMC_PxxIN          SPI_PxxIN
#define MMC_PxOUT         SPI_PxOUT      
#define MMC_PxxOUT         SPI_PxxOUT
#define MMC_SIMO          SPI_SIMO
#define MMC_SOMI          SPI_SOMI
#define MMC_UCLK          SPI_UCLK

// Chip Select
#define MMC_CS_PxOUT      P3OUT
#define MMC_CS_PxDIR      P3DIR
#define MMC_CS            BIT6

// Card Detect
#define MMC_CD_PxIN       P9IN
#define MMC_CD_PxDIR      P9DIR
#define MMC_CD            BIT0

/*
// Chip Select
#define MMC_CS_PxOUT      P3OUT
#define MMC_CS_PxDIR      P3DIR
#define MMC_CS            0x10

// Card Detect
#define MMC_CD_PxIN       P3IN
#define MMC_CD_PxDIR      P3DIR
#define MMC_CD            0x00
*/

#define CS_LOW()    MMC_CS_PxOUT &= ~MMC_CS               // Card Select
#define CS_HIGH()   while(halSPITXDONE); MMC_CS_PxOUT |= MMC_CS  // Card Deselect

#define DUMMY_CHAR 0xFF
