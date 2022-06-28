#byte TOSU = 0xFFF
#word TOS = 0xFFD
#byte STKPTR = 0xFFC
#bit    SP0 = STKPTR.0
#bit    SP1 = STKPTR.1
#bit    SP2 = STKPTR.2
#bit    SP3 = STKPTR.3
#bit    SP4 = STKPTR.4
#bit    STKOVF = STKPTR.7
#byte STKPTR = 0xFFC
#bit    STKPTR0 = STKPTR.0
#bit    STKPTR1 = STKPTR.1
#bit    STKPTR2 = STKPTR.2
#bit    STKPTR3 = STKPTR.3
#bit    STKPTR4 = STKPTR.4
#bit    STKUNF = STKPTR.6
#bit    STKFUL = STKPTR.7
#byte PCLATU = 0xFFB
#byte PCLATH = 0xFFA
#byte PCL = 0xFF9
#byte TBLPTRU = 0xFF8
#bit    TBLPTRU0 = TBLPTRU.0
#bit    TBLPTRU1 = TBLPTRU.1
#bit    TBLPTRU2 = TBLPTRU.2
#bit    TBLPTRU3 = TBLPTRU.3
#bit    TBLPTRU4 = TBLPTRU.4
#bit    ACSS = TBLPTRU.5
#word TBLPTR = 0xFF6
#byte TABLAT = 0xFF5
#word PROD = 0xFF3
#byte INTCON = 0xFF2
#bit    GIEL = INTCON.6
#bit    GIEH = INTCON.7
#byte INTCON = 0xFF2
#bit    INT0F = INTCON.1
#bit    T0IF = INTCON.2
#bit    INT0E = INTCON.4
#bit    T0IE = INTCON.5
#bit    PEIE = INTCON.6
#bit    GIE = INTCON.7
#byte INTCON = 0xFF2
#bit    RBIF = INTCON.0
#bit    INT0IF = INTCON.1
#bit    TMR0IF = INTCON.2
#bit    RBIE = INTCON.3
#bit    INT0IE = INTCON.4
#bit    TMR0IE = INTCON.5
#bit    PEIE_GIEL = INTCON.6
#bit    GIE_GIEH = INTCON.7
#byte INTCON2 = 0xFF1
#bit    RBIP = INTCON2.0
#bit    TMR0IP = INTCON2.2
#bit    INTEDG2 = INTCON2.4
#bit    INTEDG1 = INTCON2.5
#bit    INTEDG0 = INTCON2.6
#bit    RBPU = INTCON2.7
#byte INTCON3 = 0xFF0
#bit    INT1F = INTCON3.0
#bit    INT2F = INTCON3.1
#bit    INT1E = INTCON3.3
#bit    INT2E = INTCON3.4
#bit    INT1P = INTCON3.6
#bit    INT2P = INTCON3.7
#byte INTCON3 = 0xFF0
#bit    INT1IF = INTCON3.0
#bit    INT2IF = INTCON3.1
#bit    INT1IE = INTCON3.3
#bit    INT2IE = INTCON3.4
#bit    INT1IP = INTCON3.6
#bit    INT2IP = INTCON3.7
#byte INDF0 = 0xFEF
#byte POSTINC0 = 0xFEE
#byte POSTDEC0 = 0xFED
#byte PREINC0 = 0xFEC
#byte PLUSW0 = 0xFEB
#word FSR0 = 0xFE9
#byte WREG = 0xFE8
#byte INDF1 = 0xFE7
#byte POSTINC1 = 0xFE6
#byte POSTDEC1 = 0xFE5
#byte PREINC1 = 0xFE4
#byte PLUSW1 = 0xFE3
#word FSR1 = 0xFE1
#byte BSR = 0xFE0
#byte INDF2 = 0xFDF
#byte POSTINC2 = 0xFDE
#byte POSTDEC2 = 0xFDD
#byte PREINC2 = 0xFDC
#byte PLUSW2 = 0xFDB
#word FSR2 = 0xFD9
#byte STATUS = 0xFD8
#bit    C = STATUS.0
#bit    DC = STATUS.1
#bit    Z = STATUS.2
#bit    OV = STATUS.3
#bit    N = STATUS.4
#word TMR0 = 0xFD6
#byte T0CON = 0xFD5
#bit    T0PS3 = T0CON.3
#bit    T016BIT = T0CON.6
#byte T0CON = 0xFD5
#bit    T0PS0 = T0CON.0
#bit    T0PS1 = T0CON.1
#bit    T0PS2 = T0CON.2
#bit    PSA = T0CON.3
#bit    T0SE = T0CON.4
#bit    T0CS = T0CON.5
#bit    T08BIT = T0CON.6
#bit    TMR0ON = T0CON.7
#byte OSCCON = 0xFD3
#bit    FLTS = OSCCON.2
#byte OSCCON = 0xFD3
#bit    SCS0 = OSCCON.0
#bit    SCS1 = OSCCON.1
#bit    IOFS = OSCCON.2
#bit    OSTS = OSCCON.3
#bit    IRCF0 = OSCCON.4
#bit    IRCF1 = OSCCON.5
#bit    IRCF2 = OSCCON.6
#bit    IDLEN = OSCCON.7
#byte HLVDCON = 0xFD2
#bit    HLVDL0 = HLVDCON.0
#bit    HLVDL1 = HLVDCON.1
#bit    HLVDL2 = HLVDCON.2
#bit    HLVDL3 = HLVDCON.3
#bit    HLVDEN = HLVDCON.4
#bit    IVRST = HLVDCON.5
#bit    VDIRMAG = HLVDCON.7
#byte HLVDCON = 0xFD2
#bit    LVDL0 = HLVDCON.0
#bit    LVDL1 = HLVDCON.1
#bit    LVDL2 = HLVDCON.2
#bit    LVDL3 = HLVDCON.3
#bit    LVDEN = HLVDCON.4
#bit    IRVST = HLVDCON.5
#byte HLVDCON = 0xFD2
#bit    LVV0 = HLVDCON.0
#bit    LVV1 = HLVDCON.1
#bit    LVV2 = HLVDCON.2
#bit    LVV3 = HLVDCON.3
#bit    BGST = HLVDCON.5
#byte WDTCON = 0xFD1
#bit    SWDTE = WDTCON.0
#byte WDTCON = 0xFD1
#bit    SWDTEN = WDTCON.0
#byte RCON = 0xFD0
#bit    BOR = RCON.0
#bit    POR = RCON.1
#bit    PD = RCON.2
#bit    TO = RCON.3
#bit    RI = RCON.4
#bit    SBOREN = RCON.6
#bit    IPEN = RCON.7
#word TMR1 = 0xFCE
#byte T1CON = 0xFCD
#bit    TMR1ON = T1CON.0
#bit    TMR1CS = T1CON.1
#bit    T1SYNC = T1CON.2
#bit    T1OSCEN = T1CON.3
#bit    T1CKPS0 = T1CON.4
#bit    T1CKPS1 = T1CON.5
#bit    T1RUN = T1CON.6
#bit    RD16 = T1CON.7
#byte TMR2 = 0xFCC
#byte PR2 = 0xFCB
#byte T2CON = 0xFCA
#bit    TOUTPS0 = T2CON.3
#bit    TOUTPS1 = T2CON.4
#bit    TOUTPS2 = T2CON.5
#bit    TOUTPS3 = T2CON.6
#byte T2CON = 0xFCA
#bit    T2CKPS0 = T2CON.0
#bit    T2CKPS1 = T2CON.1
#bit    TMR2ON = T2CON.2
#bit    T2OUTPS0 = T2CON.3
#bit    T2OUTPS1 = T2CON.4
#bit    T2OUTPS2 = T2CON.5
#bit    T2OUTPS3 = T2CON.6
#byte SSPBUF = 0xFC9
#byte SSPADD = 0xFC8
#byte SSPSTAT = 0xFC7
#bit    WRITE = SSPSTAT.2
#bit    ADDRESS = SSPSTAT.5
#byte SSPSTAT = 0xFC7
#bit    R_W = SSPSTAT.2
#bit    D_A = SSPSTAT.5
#byte SSPSTAT = 0xFC7
#bit    W = SSPSTAT.2
#bit    A = SSPSTAT.5
#byte SSPSTAT = 0xFC7
#bit    BF = SSPSTAT.0
#bit    UA = SSPSTAT.1
#bit    R = SSPSTAT.2
#bit    S = SSPSTAT.3
#bit    P = SSPSTAT.4
#bit    D = SSPSTAT.5
#bit    CKE = SSPSTAT.6
#bit    SMP = SSPSTAT.7
#byte SSPCON1 = 0xFC6
#bit    SSPM0 = SSPCON1.0
#bit    SSPM1 = SSPCON1.1
#bit    SSPM2 = SSPCON1.2
#bit    SSPM3 = SSPCON1.3
#bit    CKP = SSPCON1.4
#bit    SSPEN = SSPCON1.5
#bit    SSPOV = SSPCON1.6
#bit    WCOL = SSPCON1.7
#byte SSPCON2 = 0xFC5
#bit    ADMSK1 = SSPCON2.1
#bit    ADMSK2 = SSPCON2.2
#bit    ADMSK3 = SSPCON2.3
#bit    ADMSK4 = SSPCON2.4
#bit    ADMSK5 = SSPCON2.5
#byte SSPCON2 = 0xFC5
#bit    SEN = SSPCON2.0
#bit    RSEN = SSPCON2.1
#bit    PEN = SSPCON2.2
#bit    RCEN = SSPCON2.3
#bit    ACKEN = SSPCON2.4
#bit    ACKDT = SSPCON2.5
#bit    ACKSTAT = SSPCON2.6
#bit    GCEN = SSPCON2.7
#word ADRES = 0xFC3
#byte ADCON0 = 0xFC2
#bit    GO_DONE = ADCON0.1
#byte ADCON0 = 0xFC2
#bit    DONE = ADCON0.1
#byte ADCON0 = 0xFC2
#bit    ADON = ADCON0.0
#bit    GO = ADCON0.1
#bit    CHS0 = ADCON0.2
#bit    CHS1 = ADCON0.3
#bit    CHS2 = ADCON0.4
#bit    CHS3 = ADCON0.5
#byte ADCON1 = 0xFC1
#bit    PCFG0 = ADCON1.0
#bit    PCFG1 = ADCON1.1
#bit    PCFG2 = ADCON1.2
#bit    PCFG3 = ADCON1.3
#bit    VCFG0 = ADCON1.4
#bit    VCFG1 = ADCON1.5
#byte ADCON2 = 0xFC0
#bit    ADCS0 = ADCON2.0
#bit    ADCS1 = ADCON2.1
#bit    ADCS2 = ADCON2.2
#bit    ACQT0 = ADCON2.3
#bit    ACQT1 = ADCON2.4
#bit    ACQT2 = ADCON2.5
#bit    ADFM = ADCON2.7
#word CCPR1 = 0xFBE
#byte CCP1CON = 0xFBD
#bit    CCP1Y = CCP1CON.4
#bit    CCP1X = CCP1CON.5
#byte CCP1CON = 0xFBD
#bit    CCP1M0 = CCP1CON.0
#bit    CCP1M1 = CCP1CON.1
#bit    CCP1M2 = CCP1CON.2
#bit    CCP1M3 = CCP1CON.3
#bit    DC1B0 = CCP1CON.4
#bit    DC1B1 = CCP1CON.5
#bit    P1M0 = CCP1CON.6
#bit    P1M1 = CCP1CON.7
#word CCPR2 = 0xFBB
#byte CCP2CON = 0xFBA
#bit    CCP2Y = CCP2CON.4
#bit    CCP2X = CCP2CON.5
#byte CCP2CON = 0xFBA
#bit    CCP2M0 = CCP2CON.0
#bit    CCP2M1 = CCP2CON.1
#bit    CCP2M2 = CCP2CON.2
#bit    CCP2M3 = CCP2CON.3
#bit    DC2B0 = CCP2CON.4
#bit    DC2B1 = CCP2CON.5
#byte BAUDCON = 0xFB8
#bit    SCKP = BAUDCON.4
#bit    RCMT = BAUDCON.6
#byte BAUDCON = 0xFB8
#bit    ABDEN = BAUDCON.0
#bit    WUE = BAUDCON.1
#bit    BRG16 = BAUDCON.3
#bit    TXCKP = BAUDCON.4
#bit    RXDTP = BAUDCON.5
#bit    RCIDL = BAUDCON.6
#bit    ABDOVF = BAUDCON.7
#byte PWM1CON = 0xFB7
#bit    PDC0 = PWM1CON.0
#bit    PDC1 = PWM1CON.1
#bit    PDC2 = PWM1CON.2
#bit    PDC3 = PWM1CON.3
#bit    PDC4 = PWM1CON.4
#bit    PDC5 = PWM1CON.5
#bit    PDC6 = PWM1CON.6
#bit    PRSEN = PWM1CON.7
#byte ECCP1AS = 0xFB6
#bit    PSSBD0 = ECCP1AS.0
#bit    PSSBD1 = ECCP1AS.1
#bit    PSSAC0 = ECCP1AS.2
#bit    PSSAC1 = ECCP1AS.3
#bit    ECCPAS0 = ECCP1AS.4
#bit    ECCPAS1 = ECCP1AS.5
#bit    ECCPAS2 = ECCP1AS.6
#bit    ECCPASE = ECCP1AS.7
#byte CVRCON = 0xFB5
#bit    CVR0 = CVRCON.0
#bit    CVR1 = CVRCON.1
#bit    CVR2 = CVRCON.2
#bit    CVR3 = CVRCON.3
#bit    CVRSS = CVRCON.4
#bit    CVRR = CVRCON.5
#bit    CVROE = CVRCON.6
#bit    CVREN = CVRCON.7
#byte CMCON = 0xFB4
#bit    CM0 = CMCON.0
#bit    CM1 = CMCON.1
#bit    CM2 = CMCON.2
#bit    CIS = CMCON.3
#bit    C1INV = CMCON.4
#bit    C2INV = CMCON.5
#bit    C1OUT = CMCON.6
#bit    C2OUT = CMCON.7
#word TMR3 = 0xFB2
#byte T3CON = 0xFB1
#bit    TMR3ON = T3CON.0
#bit    TMR3CS = T3CON.1
#bit    T3SYNC = T3CON.2
#bit    T3CCP1 = T3CON.3
#bit    T3CKPS0 = T3CON.4
#bit    T3CKPS1 = T3CON.5
#bit    T3CCP2 = T3CON.6
#bit    RD16 = T3CON.7
#byte SPBRGH = 0xFB0
#byte SPBRG = 0xFAF
#byte RCREG = 0xFAE
#byte TXREG = 0xFAD
#byte TXSTA = 0xFAC
#bit    TX9D = TXSTA.0
#bit    TRMT = TXSTA.1
#bit    BRGH = TXSTA.2
#bit    SENDB = TXSTA.3
#bit    SYNC = TXSTA.4
#bit    TXEN = TXSTA.5
#bit    TX9 = TXSTA.6
#bit    CSRC = TXSTA.7
#byte RCSTA = 0xFAB
#bit    ADEN = RCSTA.3
#byte RCSTA = 0xFAB
#bit    RX9D = RCSTA.0
#bit    OERR = RCSTA.1
#bit    FERR = RCSTA.2
#bit    ADDEN = RCSTA.3
#bit    CREN = RCSTA.4
#bit    SREN = RCSTA.5
#bit    RX9 = RCSTA.6
#bit    SPEN = RCSTA.7
#byte EEADR = 0xFA9
#byte EEDATA = 0xFA8
#byte EECON2 = 0xFA7
#byte EECON1 = 0xFA6
#bit    RD = EECON1.0
#bit    WR = EECON1.1
#bit    WREN = EECON1.2
#bit    WRERR = EECON1.3
#bit    FREE = EECON1.4
#bit    CFGS = EECON1.6
#bit    EEPGD = EECON1.7
#byte IPR2 = 0xFA2
#bit    LVDIP = IPR2.2
#byte IPR2 = 0xFA2
#bit    CCP2IP = IPR2.0
#bit    TMR3IP = IPR2.1
#bit    HLVDIP = IPR2.2
#bit    BCLIP = IPR2.3
#bit    EEIP = IPR2.4
#bit    CMIP = IPR2.6
#bit    OSCFIP = IPR2.7
#byte PIR2 = 0xFA1
#bit    LVDIF = PIR2.2
#byte PIR2 = 0xFA1
#bit    CCP2IF = PIR2.0
#bit    TMR3IF = PIR2.1
#bit    HLVDIF = PIR2.2
#bit    BCLIF = PIR2.3
#bit    EEIF = PIR2.4
#bit    CMIF = PIR2.6
#bit    OSCFIF = PIR2.7
#byte PIE2 = 0xFA0
#bit    LVDIE = PIE2.2
#byte PIE2 = 0xFA0
#bit    CCP2IE = PIE2.0
#bit    TMR3IE = PIE2.1
#bit    HLVDIE = PIE2.2
#bit    BCLIE = PIE2.3
#bit    EEIE = PIE2.4
#bit    CMIE = PIE2.6
#bit    OSCFIE = PIE2.7
#byte IPR1 = 0xF9F
#bit    TMR1IP = IPR1.0
#bit    TMR2IP = IPR1.1
#bit    CCP1IP = IPR1.2
#bit    SSPIP = IPR1.3
#bit    TXIP = IPR1.4
#bit    RCIP = IPR1.5
#bit    ADIP = IPR1.6
#bit    PSPIP = IPR1.7
#byte PIR1 = 0xF9E
#bit    TMR1IF = PIR1.0
#bit    TMR2IF = PIR1.1
#bit    CCP1IF = PIR1.2
#bit    SSPIF = PIR1.3
#bit    TXIF = PIR1.4
#bit    RCIF = PIR1.5
#bit    ADIF = PIR1.6
#bit    PSPIF = PIR1.7
#byte PIE1 = 0xF9D
#bit    TMR1IE = PIE1.0
#bit    TMR2IE = PIE1.1
#bit    CCP1IE = PIE1.2
#bit    SSPIE = PIE1.3
#bit    TXIE = PIE1.4
#bit    RCIE = PIE1.5
#bit    ADIE = PIE1.6
#bit    PSPIE = PIE1.7
#byte OSCTUNE = 0xF9B
#bit    TUN0 = OSCTUNE.0
#bit    TUN1 = OSCTUNE.1
#bit    TUN2 = OSCTUNE.2
#bit    TUN3 = OSCTUNE.3
#bit    TUN4 = OSCTUNE.4
#bit    PLLEN = OSCTUNE.6
#bit    INTSRC = OSCTUNE.7
#byte TRISE = 0xF96
#bit    TRISE0 = TRISE.0
#bit    TRISE1 = TRISE.1
#bit    TRISE2 = TRISE.2
#bit    PSPMODE = TRISE.4
#bit    IBOV = TRISE.5
#bit    OBF = TRISE.6
#bit    IBF = TRISE.7
#byte TRISD = 0xF95
#byte TRISC = 0xF94
#byte TRISB = 0xF93
#byte TRISA = 0xF92
#byte LATE = 0xF8D
#byte LATD = 0xF8C
#byte LATC = 0xF8B
#byte LATB = 0xF8A
#byte LATA = 0xF89
#byte PORTE = 0xF84
#byte PORTD = 0xF83
#byte PORTC = 0xF82
#byte PORTB = 0xF81
#byte PORTA = 0xF80
