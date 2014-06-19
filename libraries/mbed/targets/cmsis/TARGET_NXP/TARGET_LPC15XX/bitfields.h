#ifndef MBED_BITFIELDS_H
#define MBED_BITFIELDS_H

//! Massage  x for use in bitfield  name.
#define BFN_PREP(x, name)    ( ((x)<<name##_SHIFT) & name##_MASK )

//! Get the value of bitfield  name from  y. Equivalent to (var=) y.name
#define BFN_GET(y, name)     ( ((y) & name##_MASK)>>name##_SHIFT )

//! Set bitfield  name from  y to  x: y.name= x.
#define BFN_SET(y, x, name)  (y = ((y)&~name##_MASK) | BFN_PREP(x,name) )


/* PRESETCTRL1, address 0x4007 4048 */
#define PRESETCTRL1_CCAN_RST_N         (1 << 7)           // C_CAN reset control. See Section 3.6.8 for part specific details.

/* SYSAHBCLKCTRL1, address 0x4007 40C8 */
#define SYSAHBCLKCTRL1_CCAN            (1 << 7)           // Enables clock for C_CAN. See Section 3.6.23 for part specific details.

/* CANCNTL, address 0x400F 0000 */
#define CANCNTL_INIT                   (1 << 0)           // Initialization
#define CANCNTL_IE                     (1 << 1)           // Module interrupt enable
#define CANCNTL_SIE                    (1 << 2)           // Status change interrupt enable
#define CANCNTL_EIE                    (1 << 3)           // Error interrupt enable
#define CANCNTL_DAR                    (1 << 5)           // Disable automatic retransmission
#define CANCNTL_CCE                    (1 << 6)           // Configuration change enable
#define CANCNTL_TEST                   (1 << 7)           // Test mode enable

/* CANSTAT, address 0x400F 0004 */
#define CANSTAT_LEC_MASK               0x0007             // Last error code Type of the last error to occur on the CAN bus.The LEC field holds a code which indicates the type of the last error to occur on the CAN bus. This field will be cleared to `0' when a message has been transferred (reception or transmission) without error. The unused code `111' may be written by the CPU to check for updates.
#define CANSTAT_LEC_SHIFT              0                 
#define CANSTAT_TXOK                   (1 << 3)           // Transmitted a message successfully This bit must be reset by the CPU. It is never reset by the CAN controller.
#define CANSTAT_RXOK                   (1 << 4)           // Received a message successfully This bit must be reset by the CPU. It is never reset by the CAN controller.
#define CANSTAT_EPASS                  (1 << 5)           // Error passive
#define CANSTAT_EWARN                  (1 << 6)           // Warning status
#define CANSTAT_BOFF                   (1 << 7)           // Busoff status

/* CANEC, address 0x400F 0008 */
#define CANEC_TEC_MASK                 0x00FF             // Transmit error counter Current value of the transmit error counter (maximum value 255)
#define CANEC_TEC_SHIFT                0                 
#define CANEC_REC_MASK                 0x7F00             // Receive error counter Current value of the receive error counter (maximum value 127).
#define CANEC_REC_SHIFT                8                 
#define CANEC_RP                       (1 << 15)          // Receive error passive

/* CANBT, address 0x400F 000C */
#define CANBT_BRP_MASK                 0x003F             // Baud rate prescaler The value by which the oscillator frequency is divided for generating the bit time quanta. The bit time is built up from a multiple of this quanta. Valid values for the Baud Rate Prescaler are 0 to 63.[1]
#define CANBT_BRP_SHIFT                0                 
#define CANBT_SJW_MASK                 0x00C0             // (Re)synchronization jump width Valid programmed values are 0 to 3.[1]
#define CANBT_SJW_SHIFT                6                 
#define CANBT_TSEG1_MASK               0x0F00             // Time segment before the sample point Valid values are 1 to                  15.[1]
#define CANBT_TSEG1_SHIFT              8                 
#define CANBT_TSEG2_MASK               0x7000             // Time segment after the sample point Valid values are 0 to                  7.[1]
#define CANBT_TSEG2_SHIFT              12                

/* CANINT, address 0x400F 0010 */
#define CANINT_INTID_MASK              0xFFFF             // 0x0000 = No interrupt is pending.                0 0x0001 - 0x0020 = Number of message object which caused the interrupt. 0x0021 - 0x7FFF = Unused 0x8000 = Status interrupt 0x8001 - 0xFFFF = Unused
#define CANINT_INTID_SHIFT             0                 

/* CANTEST, address 0x400F 0014 */
#define CANTEST_BASIC                  (1 << 2)           // Basic mode
#define CANTEST_SILENT                 (1 << 3)           // Silent mode
#define CANTEST_LBACK                  (1 << 4)           // Loop back mode
#define CANTEST_TX_MASK                0x0060             // Control of CAN_TXD pins
#define CANTEST_TX_SHIFT               5                 
#define CANTEST_RX                     (1 << 7)           // Monitors the actual value of the CAN_RXD pin.

/* CANBRPE, address 0x400F 0018 */
#define CANBRPE_BRPE_MASK              0x000F             // Baud rate prescaler extension By programming BRPE the Baud Rate Prescaler can be extended to values up to 1023. Hardware interprets the value as the value of BRPE (MSBs) and BRP (LSBs) plus one. Allowed values are 0 to 15.
#define CANBRPE_BRPE_SHIFT             0                 

/* CANIF1_CMDREQ, address 0x400F 0020 and CANIF2_CMDREQ, address 0x400F 0080 */
#define CANIFn_CMDREQ_MN_MASK          0x003F             // Message number 0x01 - 0x20 = Valid message numbers. The message object in the message RAM is selected for data transfer. 0x00 = Not a valid message number. This value is interpreted as 0x20.[1] 0x21 - 0x3F = Not a valid message number. This value is interpreted as 0x01 - 0x1F.[1]
#define CANIFn_CMDREQ_MN_SHIFT         0                 
#define CANIFn_CMDREQ_BUSY             (1 << 15)          // BUSY flag

/* CANIF1_CMDMSK, address 0x400F 0024 and CANIF2_CMDMSK, address 0x400F 0084 */
#define CANIFn_CMDMSK_DATA_B           (1 << 0)           // Access data bytes 4-7
#define CANIFn_CMDMSK_DATA_A           (1 << 1)           // Access data bytes 0-3
#define CANIFn_CMDMSK_TXRQST           (1 << 2)           // Access transmission request bit (Write direction)
#define CANIFn_CMDMSK_NEWDAT           (1 << 2)           // Access new data bit (Read direction)
#define CANIFn_CMDMSK_CLRINTPND        (1 << 3)           // This bit is ignored in the write direction.
#define CANIFn_CMDMSK_CTRL             (1 << 4)           // Access control bits
#define CANIFn_CMDMSK_ARB              (1 << 5)           // Access arbitration bits
#define CANIFn_CMDMSK_MASK             (1 << 6)           // Access mask bits
#define CANIFn_CMDMSK_WR               (1 << 7)           // Write transfer Transfer data from the selected message buffer registers to the message object addressed by the command request register CANIFn_CMDREQ.
#define CANIFn_CMDMSK_RD               (0 << 7)           // Read transfer Read data from the selected message buffer registers to the message object addressed by the command request register CANIFn_CMDREQ.

/* CANIF1_MSK1, address 0x400F 0028 and CANIF2_MASK1, address 0x400F 0088 */
#define CANIFn_MSK1_MSK_MASK           0xFFFF             // Identifier mask
#define CANIFn_MSK1_MSK_SHIFT          0                 

/* CANIF1_MSK2, address 0x400F 002C and CANIF2_MASK2, address 0x400F 008C */
#define CANIFn_MSK2_MSK_MASK           0x1FFF             // Identifier mask
#define CANIFn_MSK2_MSK_SHIFT          0                 
#define CANIFn_MSK2_MDIR               (1 << 14)          // Mask message direction
#define CANIFn_MSK2_MXTD               (1 << 15)          // Mask extend identifier

/* CANIF1_ARB1, address 0x400F 0030 and CANIF2_ARB1, address 0x400F 0090 */
#define CANIFn_ARB1_ID_MASK            0xFFFF             // Message identifier 29-bit identifier (extended frame) 11-bit identifier (standard frame)
#define CANIFn_ARB1_ID_SHIFT           0                 

/* CANIF1_ARB2, address 0x400F 0034 and CANIF2_ARB2, address 0x400F 0094 */
#define CANIFn_ARB2_ID_MASK            0x1FFF             // Message identifier 29-bit identifier (extended frame) 11-bit identifier (standard frame)
#define CANIFn_ARB2_ID_SHIFT           0                 
#define CANIFn_ARB2_DIR                (1 << 13)          // Message direction
#define CANIFn_ARB2_XTD                (1 << 14)          // Extend identifier
#define CANIFn_ARB2_MSGVAL             (1 << 15)          // Message valid Remark: The CPU must reset the MSGVAL bit of all unused Messages Objects during the initialization before it resets bit INIT in the CAN Control Register. This bit must also be reset before the identifier ID28:0, the control bits XTD, DIR, or the Data Length Code DLC3:0 are modified, or if the Messages Object is no longer required.

/* CANIF1_MCTRL, address 0x400F 0038 and CANIF2_MCTRL, address 0x400F 0098 */
#define CANIFn_MCTRL_DLC_MASK          0x000F             // Data length code Remark: The Data Length Code of a Message Object must be defined the same as in all the corresponding objects with the same identifier at other nodes. When the Message Handler stores a data frame, it will write the DLC to the value given by the received message. 0000 - 1000 = Data frame has 0 - 8 data bytes. 1001 - 1111 = Data frame has 8 data bytes.
#define CANIFn_MCTRL_DLC_SHIFT         0                 
#define CANIFn_MCTRL_EOB               (1 << 7)           // End of buffer
#define CANIFn_MCTRL_TXRQST            (1 << 8)           // Transmit request
#define CANIFn_MCTRL_RMTEN             (1 << 9)           // Remote enable
#define CANIFn_MCTRL_RXIE              (1 << 10)          // Receive interrupt enable
#define CANIFn_MCTRL_TXIE              (1 << 11)          // Transmit interrupt enable
#define CANIFn_MCTRL_UMASK             (1 << 12)          // Use acceptance mask Remark: If UMASK is set to 1, the message object's mask bits have to be programmed during initialization of the message object before MAGVAL is set to 1.
#define CANIFn_MCTRL_INTPND            (1 << 13)          // Interrupt pending
#define CANIFn_MCTRL_MSGLST            (1 << 14)          // Message lost (only valid for message objects in the direction receive).
#define CANIFn_MCTRL_NEWDAT            (1 << 15)          // New data

/* CANIF1_DA1, address 0x400F 003C and CANIF2_DA1, address 0x400F 009C */
#define CANIFn_DA1_DATA0_MASK          0x00FF             // Data byte 0
#define CANIFn_DA1_DATA0_SHIFT         0                 
#define CANIFn_DA1_DATA1_MASK          0xFF00             // Data byte 1
#define CANIFn_DA1_DATA1_SHIFT         8                 

/* CANIF1_DA2, address 0x400F 0040 and CANIF2_DA2, address 0x400F 00A0 */
#define CANIFn_DA2_DATA2_MASK          0x00FF             // Data byte 2
#define CANIFn_DA2_DATA2_SHIFT         0                 
#define CANIFn_DA2_DATA3_MASK          0xFF00             // Data byte 3
#define CANIFn_DA2_DATA3_SHIFT         8                 

/* CANIF1_DB1, address 0x400F 0044 and CANIF2_DB1, address 0x400F 00A4 */
#define CANIFn_DB1_DATA4_MASK          0x00FF             // Data byte 4
#define CANIFn_DB1_DATA4_SHIFT         0                 
#define CANIFn_DB1_DATA5_MASK          0xFF00             // Data byte 5
#define CANIFn_DB1_DATA5_SHIFT         8                 

/* CANIF1_DB2, address 0x400F 0048 and CANIF2_DB2, address 0x400F 00A8 */
#define CANIFn_DB2_DATA6_MASK          0x00FF             // Data byte 6
#define CANIFn_DB2_DATA6_SHIFT         0                 
#define CANIFn_DB2_DATA7_MASK          0xFF00             // Data byte 7
#define CANIFn_DB2_DATA7_SHIFT         8                 

/* CANTXREQ1, address 0x400F 0100 */
#define CANTXREQ1_TXRQST_MASK          0xFFFF             // Transmission request bit of message objects 16 to 1. 0 = This message object is not waiting for transmission. 1 = The transmission of this message object is requested and not yet done. Reserved
#define CANTXREQ1_TXRQST_SHIFT         0                 

/* CANTXREQ2, address 0x400F 0104 */
#define CANTXREQ2_TXRQST_MASK          0xFFFF             // Transmission request bit of message objects 32 to 17. 0 = This message object is not waiting for transmission. 1 = The transmission of this message object is requested and not yet done. Reserved
#define CANTXREQ2_TXRQST_SHIFT         0                 

/* CANND1, address 0x400F 0120 */
#define CANND1_NEWDAT_MASK             0xFFFF             // New data bits of message objects 16 to 1. 0 = No new data has been written into the data portion of this Message Object by the Message Handler since last time this flag was cleared by the CPU. 1 = The Message Handler or the CPU has written new data into the data portion of this Message Object.
#define CANND1_NEWDAT_SHIFT            0                 

/* CANND2, address 0x400F 0124 */
#define CANND2_NEWDAT_MASK             0xFFFF             // New data bits of message objects 32 to 17. 0 = No new data has been written into the data portion of this Message Object by the Message Handler since last time this flag was cleared by the CPU. 1 = The Message Handler or the CPU has written new data into the data portion of this Message Object.
#define CANND2_NEWDAT_SHIFT            0                 

/* CANIR1, address 0x400F 0140 */
#define CANIR1_INTPND_INTERRUPT_MASK   0xFFFF             // pending bits of message objects 16 to 1. essage object is ignored by the message essage object is the source of an interrupt. Reserved
#define CANIR1_INTPND_INTERRUPT_SHIFT  0                 

/* CANIR2, addresses 0x400F 0144 */
#define CANIR2_INTPND_MASK             0xFFFF             // Interrupt pending bits of message objects 32 to 17. 0 = This message object is ignored by the message handler. 1 = This message object is the source of an interrupt. Reserved
#define CANIR2_INTPND_SHIFT            0                 

/* CANMSGV1, addresses 0x400F 0160 */
#define CANMSGV1_MSGVAL_MASK           0xFFFF             // Message valid bits of message objects 16 to 1. 0 = This message object is ignored by the message handler. 1 = This message object is configured and should be considered by the message handler. Reserved
#define CANMSGV1_MSGVAL_SHIFT          0                 

/* CANMSGV2, address 0x400F 0164 */
#define CANMSGV2_MSGVAL_MASK           0xFFFF             // Message valid bits of message objects 32 to 17. 0 = This message object is ignored by the message handler. 1 = This message object is configured and should be considered by the message handler. Reserved
#define CANMSGV2_MSGVAL_SHIFT          0                 

/* CANCLKDIV, address 0x400F 0180 */
#define CANCLKDIV_CLKDIVVAL_MASK       0x000F             // Clock divider value. CAN_CLK = PCLK/(CLKDIVVAL +1) 0000: CAN_CLK = PCLK divided by 1. 0001: CAN_CLK = PCLK divided by 2. 0010: CAN_CLK = PCLK divided by 3 0011: CAN_CLK = PCLK divided by 4. ... 1111: CAN_CLK = PCLK divided by 16.
#define CANCLKDIV_CLKDIVVAL_SHIFT      0                 

#endif
