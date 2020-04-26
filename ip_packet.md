Тип сервиса [2-ой октет]  
Bits 0-2[PR]: Precedence.  
Bit 3[D]    : 0 = Normal Delay, 1 = Low Delay.  
Bit 4[T]    : 0 = Normal Throughput, 1 = High Throughput.  
Bit 5[R]    : 0 = Normal Relibility, 1 = High Relibility.  
Bit 6-7     : Reserved for Future Use.  
  
Precedence [PR][9-11 биты, начало второго октета]  
111 - Network Control 011 - Flash  
110 - Internetwork Control 010 - Immediate  
101 - CRITIC/ECP 001 - Priority  
100 - Flash Override 000 - Routine  
  
Flags [3 бита,6 поле, 49-51 биты, начало 7 октета]   
Bit 0: reserved, must be zero   
Bit 1[D]: (DF) 0 = May Fragment, 1 = Don't Fragment.   
Bit 2[M]: (MF) 0 = Last Fragment, 1 = More Fragments.   
