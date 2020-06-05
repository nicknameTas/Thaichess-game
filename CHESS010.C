#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
int get_code(void);
void wellcome(void);
void loadstart(void);
void menu(void);
void background(void);
void play(void);
void detectmouse(void);
void walker();
void chip();
void bia();
void deletebox();
int box_bar[8][8][13];
union REGS i, o;
main(){
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
   setbkcolor(0);
   wellcome();
   loadstart();
   menu();
   getch();
   i.x.ax = 1;
   int86 (0X33,&i,&o);
   closegraph();
   return 0;
}
void detectmouse (void){
  i.x.ax = 0;
  int86 (0X33,&i,&o);}
static int get_code ( void ){
  int ch = getch();
  if ( ch == 0 || ch == 224 )
    ch = 256 + getch();
  return ch;}
void deletebox(int box1,int box2 ,int box3 ,int box4 ,int color){
      setfillstyle(1,color);
      bar(box1,box2,box3,box4);
      setcolor(15);
      rectangle(box1,box2,box3,box4);}
void wellcome(void){
   int font=3;
   int x=getmaxx()/2;
   int y=getmaxy()/2;
   settextstyle(font,HORIZ_DIR,1);setcolor(15);
   outtextxy(x-200,y,"WELCOME TO THE GAME CHESS By Nitas Srisanoi");
   delay(2000);}
void loadstart(void){
   int i =0;
   setcolor(15);
   for(i=0;i<130;i++){
    outtextxy(0+(i*5),470,"§");
    delay(50);}
  cleardevice();
}
void menu(){
   int menu_sel=0;
   int sound_random=100;
   int sound_delay=200;
   int ch,x,y,font=3,menu=1;
   x=getmaxx()/2;
   y=getmaxy()/2;
   while(menu_sel<=0){
     sound(10*random(sound_random));
     delay(sound_delay);
     nosound();
     switch(menu){
       case 1: cleardevice();
       settextstyle(font, HORIZ_DIR, 1);setcolor(15);
       outtextxy(x-50,(y/2)+75,"GAME CHESS THAILAND");
       outtextxy(x-80,(y/2)+100,"[---->START GAME<----]");
       outtextxy(x-80,(y/2)+115,"      OPTION     ");
       outtextxy(x-80,(y/2)+130,"      EXIT  GAME    "); break;
       case 2: cleardevice();
       settextstyle(font, HORIZ_DIR, 1);setcolor(15);
       outtextxy(x-50,(y/2)+75,"GAME CHESS THAILAND");
       outtextxy(x-80,(y/2)+100,"      START GAME    ");
       outtextxy(x-80,(y/2)+115,"[---->OPTION<----]");
       outtextxy(x-80,(y/2)+130,"      EXIT  GAME    "); break;
       case 3:cleardevice();
       settextstyle(font, HORIZ_DIR, 1);setcolor(15);
       outtextxy(x-50,(y/2)+75,"GAME CHESS THAILAND");
       outtextxy(x-80,(y/2)+100,"     START GAME    ");
       outtextxy(x-80,(y/2)+115,"     OPTION      ");
       outtextxy(x-80,(y/2)+130,"[---->EXIT  GAME<----]"); break;}
      if(kbhit()){
      ch = get_code();
      switch(ch){
      case 328:switch(menu){case 1:menu=2;break;
			    case 2:menu=3;break;
			    case 3:menu=1;break;}break;
      case 336:switch(menu){case 1:menu=2;break;
			    case 2:menu=3;break;
			    case 3:menu=1;break;}break;
      case 27:exit(0);break;
      case 13:switch(menu){
	      case 1:background();
	      play();
	      setcolor(8);break;
	      case 2:printf("Coming soon!!!!");break;
	      case 3:exit(0);break;}break;}
     } 
   }
} //end menu
void play(void){
   int x, y;
   int loopbar_1,loopbar_2,checkbar1,checkbar2,user=1,check=1;
   i.x.ax=1;
   int86(0x33,&i,&i);
   while(check==1 )
   {
       i.x.ax=3;
       x=i.x.cx;
       y=i.x.dx;
       int86(0x33,&i,&i);
       for(loopbar_1=0;loopbar_1<=7;loopbar_1++){
	    for(loopbar_2=0;loopbar_2<=7;loopbar_2++){
	  if(box_bar[loopbar_1][loopbar_2][5] != 0 ){
	       switch(box_bar[loopbar_1][loopbar_2][5]){
		  case 1:setcolor(1);break;
		  case 12:setcolor(14);break;
		  case 13:setcolor(4);break;}
		  rectangle(box_bar[loopbar_1][loopbar_2][0]+1,box_bar[loopbar_1][loopbar_2][1]+1,box_bar[loopbar_1][loopbar_2][2]-1,box_bar[loopbar_1][loopbar_2][3]-1);}
	   if(x>box_bar[loopbar_1][loopbar_2][0] && x<box_bar[loopbar_1][loopbar_2][2] && y>box_bar[loopbar_1][loopbar_2][1] && y<box_bar[loopbar_1][loopbar_2][3] && i.x.bx ==1  && x>125 && x<515 && y>45 && y<435){
	    if(box_bar[loopbar_1][loopbar_2][7] == 0){ 
	     if(box_bar[loopbar_1][loopbar_2][4] != 0){
		   for(checkbar1=0;checkbar1<=7;checkbar1++){
		    for(checkbar2=0;checkbar2<=7;checkbar2++){
		      if(box_bar[checkbar1][checkbar2][5]==1||box_bar[checkbar1][checkbar2][5]==12||box_bar[checkbar1][checkbar2][5]==13){
			    setcolor(box_bar[checkbar1][checkbar2][6]);
			    box_bar[checkbar1][checkbar2][5] = 0;
			    box_bar[checkbar1][checkbar2][7] = 0;
			    box_bar[checkbar1][checkbar2][8] = 0;
			    box_bar[checkbar1][checkbar2][9] = 0;
			    box_bar[checkbar1][checkbar2][10] = 0;
			    box_bar[checkbar1][checkbar2][11] = 0;
			    box_bar[checkbar1][checkbar2][12] = 0;
			    rectangle(box_bar[checkbar1][checkbar2][0]+1,box_bar[checkbar1][checkbar2][1]+1,box_bar[checkbar1][checkbar2][2]-1,box_bar[checkbar1][checkbar2][3]-1);
		      }
		    }
		    }
	     if( box_bar[loopbar_1][loopbar_2][4] == 11 || box_bar[loopbar_1][loopbar_2][4] == 21 || box_bar[loopbar_1][loopbar_2][4] == 31 ||box_bar[loopbar_1][loopbar_2][4] == 100){
	      if(user == 1 ){
	       setcolor(0);
	       rectangle(box_bar[loopbar_1][loopbar_2][0]+1,box_bar[loopbar_1][loopbar_2][1]+1,box_bar[loopbar_1][loopbar_2][2]-1,box_bar[loopbar_1][loopbar_2][3]-1);
	       box_bar[loopbar_1][loopbar_2][5] = 1;
		  if(box_bar[loopbar_1][loopbar_2][4] == 11   ){ //player 1
		     chip(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],box_bar[loopbar_1][loopbar_2][2],box_bar[loopbar_1][loopbar_2][3],box_bar[loopbar_1][loopbar_2][4],box_bar[loopbar_1][loopbar_2][6]);}
		  if(box_bar[loopbar_1][loopbar_2][4] == 100  ){ //player 1
		     bia(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],box_bar[loopbar_1][loopbar_2][2],box_bar[loopbar_1][loopbar_2][3],box_bar[loopbar_1][loopbar_2][4],box_bar[loopbar_1][loopbar_2][6]);}
			 }
	      }else{
	       if(user==2){
	       setcolor(0);
	       rectangle(box_bar[loopbar_1][loopbar_2][0]+1,box_bar[loopbar_1][loopbar_2][1]+1,box_bar[loopbar_1][loopbar_2][2]-1,box_bar[loopbar_1][loopbar_2][3]-1);
	       box_bar[loopbar_1][loopbar_2][5] = 1;
		  if( box_bar[loopbar_1][loopbar_2][4] == 12 ){ //player  2
		     chip(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],box_bar[loopbar_1][loopbar_2][2],box_bar[loopbar_1][loopbar_2][3],box_bar[loopbar_1][loopbar_2][4],box_bar[loopbar_1][loopbar_2][6]);}
		  if(box_bar[loopbar_1][loopbar_2][4] == 200  ){ //player 2
		     bia(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],box_bar[loopbar_1][loopbar_2][2],box_bar[loopbar_1][loopbar_2][3],box_bar[loopbar_1][loopbar_2][4],box_bar[loopbar_1][loopbar_2][6]);}
			 }
	       }
	    }
	    }else{
		   i.x.ax=4;
		   i.x.cx=61;
		       i.x.dx=240;
		       int86(0x33,&i,&o);
		   if(user == 1){user = 2;
		   }else{user=1;}
		  if(box_bar[loopbar_1][loopbar_2][4] == 31){check = 20;}
		  if(box_bar[loopbar_1][loopbar_2][4] == 32){check = 10; }
		  deletebox(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],box_bar[loopbar_1][loopbar_2][2],box_bar[loopbar_1][loopbar_2][3],box_bar[loopbar_1][loopbar_2][6]);
		  deletebox(box_bar[loopbar_1][loopbar_2][7],box_bar[loopbar_1][loopbar_2][8],box_bar[loopbar_1][loopbar_2][9],box_bar[loopbar_1][loopbar_2][10],box_bar[loopbar_1][loopbar_2][11]);
		   switch(box_bar[loopbar_1][loopbar_2][12]){
		   case 11:
			walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],1,1);
		   break;
		   case 12:
		       walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],2,1);
		   break;
		   case 21:
			walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],1,2);
		   break;
		   case 22:
			walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],2,2);
		   break;
		   case 31:
			walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],1,3);
		   break;
		   case 32:
			walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],2,3);
		   break;
		   case 100:
			walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],1,4);
		   break;
		   case 200:
			walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],2,4);
		   break;
		   }
		   for(checkbar1=0;checkbar1<=7;checkbar1++){
		    for(checkbar2=0;checkbar2<=7;checkbar2++){
		       if(box_bar[checkbar1][checkbar2][0] == box_bar[loopbar_1][loopbar_2][7] && box_bar[checkbar1][checkbar2][1] == box_bar[loopbar_1][loopbar_2][8]  ){
			  box_bar[checkbar1][checkbar2][4] = 0 ;
			  box_bar[checkbar1][checkbar2][5] = 0 ;
		       } 
		    }
		    }
		    for(checkbar1=0;checkbar1<=7;checkbar1++){
		     for(checkbar2=0;checkbar2<=7;checkbar2++){
			  box_bar[checkbar1][checkbar2][5]= 0 ;
			  setcolor(box_bar[checkbar1][checkbar2][6]);
			  box_bar[checkbar1][checkbar2][7]=0;
			  box_bar[checkbar1][checkbar2][8]=0;
			  box_bar[checkbar1][checkbar2][9]=0;
			  box_bar[checkbar1][checkbar2][10]=0;
			  box_bar[checkbar1][checkbar2][11]=0;
			  rectangle(box_bar[checkbar1][checkbar2][0]+1,box_bar[checkbar1][checkbar2][1]+1,box_bar[checkbar1][checkbar2][2]-1,box_bar[checkbar1][checkbar2][3]-1);
		    }
		    }
		   box_bar[loopbar_1][loopbar_2][4]=box_bar[loopbar_1][loopbar_2][12];
		   box_bar[loopbar_1][loopbar_2][12]=0;
	    }
	   }
	  }
     }
    }
    if(check==10){cleardevice();outtextxy(300,220,"Player 1 Win!!!");delay(3000);}
    else if(check==20){cleardevice();outtextxy(300,220,"Player 2 Win!!!");delay(3000);}
 }
void background(void){
  int loopbar_1,loopbar_2,number1=1,number2=1,i=1;
  cleardevice();
  setbkcolor(0);
  for(loopbar_1=0;loopbar_1<=7;loopbar_1++){
     if(number1 == 1){number2=1;number1=2;}
       else{number2=2;number1=1;}
    for(loopbar_2=0;loopbar_2<=7;loopbar_2++){
     if(number2==1){setfillstyle(1,7);number2=2;
	 box_bar[loopbar_1][loopbar_2][6]=7;}
       else{
	 setfillstyle(1,7);number2=1;
	 box_bar[loopbar_1][loopbar_2][6]=8;}
      box_bar[loopbar_1][loopbar_2][0] = 126+((46)*loopbar_2);
      box_bar[loopbar_1][loopbar_2][1] = 46+((46)*loopbar_1);
      box_bar[loopbar_1][loopbar_2][2] = 172+((46)*loopbar_2);
      box_bar[loopbar_1][loopbar_2][3] = 92+((46)*loopbar_1);
      box_bar[loopbar_1][loopbar_2][4] = 0;
      box_bar[loopbar_1][loopbar_2][5] = 0;
      box_bar[loopbar_1][loopbar_2][7] = 0;
      box_bar[loopbar_1][loopbar_2][8] = 0;
      box_bar[loopbar_1][loopbar_2][9] = 0;
      box_bar[loopbar_1][loopbar_2][10] = 0;
      box_bar[loopbar_1][loopbar_2][11] = 0;
      box_bar[loopbar_1][loopbar_2][12] = 0;
      bar(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],box_bar[loopbar_1][loopbar_2][2],box_bar[loopbar_1][loopbar_2][3]);
      setcolor(15);
      rectangle(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],box_bar[loopbar_1][loopbar_2][2],box_bar[loopbar_1][loopbar_2][3]);
	 if(i > 16 && i < 25 ){
	      walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],2,1);
	       box_bar[loopbar_1][loopbar_2][4] = 12;}
	 if(i > 40 && i < 49){
	       walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],1,1);
		box_bar[loopbar_1][loopbar_2][4] = 11;}
	 if(i == 2 || i == 7){
	      walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],2,2);
	      box_bar[loopbar_1][loopbar_2][4] = 22;}
	 if(i == 58 || i == 63){
	      walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],1,2);
	      box_bar[loopbar_1][loopbar_2][4] = 21; }
	 if(i == 5){
	       walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],2,3);
	       box_bar[loopbar_1][loopbar_2][4] = 32;}
	 if(i == 60){
	      walker(box_bar[loopbar_1][loopbar_2][0],box_bar[loopbar_1][loopbar_2][1],1,3);
	       box_bar[loopbar_1][loopbar_2][4]=31;}
      i++;
    }
  }
}
void walker(int x , int y,int player , int type){
     switch(type){
         case 1:if(player==1){
                setcolor(4);//bia1
             	setfillstyle(1,4);
	            sector(x+23,y+23,0,360,15,15);}
           else{setcolor(1);//bia 2
        	    setfillstyle(1,1);
	            sector(x+23,y+23,0,360,15,15);}break;
         case 2:if(player==1){
                setcolor(4);// horse player1
             	setfillstyle(1,4);
	            sector(x+23,y+21.5,0,360,12,12);
	            sector(x+23+6,y+13,0,360,4,6);
	            sector(x+23-6,y+13,0,360,4,6);}
           else{setcolor(1);//horse player 2
        	    setfillstyle(1,1);
	            sector(x+23,y+21.5,0,360,12,12);
	            sector(x+23+6,y+13,0,360,4,6);
	            sector(x+23-6,y+13,0,360,4,6);} break;
         case 3:if(player == 1){
                setcolor(4);//khun 1
             	setfillstyle(1,4);
             	sector(x+23,y+11.5,0,360,10,5);
	            sector(x+23,y+25,0,360,13,15);}
           else{setcolor(1);
        	    setfillstyle(1,1);
        	    sector(x+23,y+11.5,0,360,10,5);
	            sector(x+23,y+25,0,360,13,15);}break;
         case 4:if(player == 1){
                setcolor(4);// khun 2
             	setfillstyle(1,4);
	            sector(x+23,y+23,0,360,15,15);}
           else{setcolor(1);
        	    setfillstyle(1,1);
	            sector(x+23,y+23,0,360,15,15);}break;
     }
}
 void chip(int p1,int p2,int p3,int p4,int player ,int color){
      int loopbar_1,loopbar_2,num=1,i;
      int chip[3][4];
      for(loopbar_1=0;loopbar_1<=7;loopbar_1++){
          for(loopbar_2=0;loopbar_2<=7;loopbar_2++){
             for(i=0;i<3;i++){
                if(player==11){//player 1
                   switch(i){
                     case 0:
                       if(p1 == box_bar[loopbar_1][loopbar_2][0] && p2-46 == box_bar[loopbar_1][loopbar_2][1] && p3 == box_bar[loopbar_1][loopbar_2][2] && p4-46 == box_bar[loopbar_1][loopbar_2][3] ){
                          if(box_bar[loopbar_1][loopbar_2][4] == 0){
                             box_bar[loopbar_1][loopbar_2][5] = 12;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             if(box_bar[loopbar_1][loopbar_2][1] == 138 && box_bar[loopbar_1][loopbar_2][3] == 184){
                                      box_bar[loopbar_1][loopbar_2][12] = 100;                        
                             }else{box_bar[loopbar_1][loopbar_2][12] = 11;}
                          }
                       }break;
                     case 1:
                        if(p1-46 == box_bar[loopbar_1][loopbar_2][0] && p2-46 == box_bar[loopbar_1][loopbar_2][1] && p3-46 == box_bar[loopbar_1][loopbar_2][2] && p4-46 == box_bar[loopbar_1][loopbar_2][3] ){
                          if(box_bar[loopbar_1][loopbar_2][4] == 12 || box_bar[loopbar_1][loopbar_2][4] == 22 || box_bar[loopbar_1][loopbar_2][4] == 32 ||box_bar[loopbar_1][loopbar_2][4] == 200 ){
                             box_bar[loopbar_1][loopbar_2][5] = 13;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             if(box_bar[loopbar_1][loopbar_2][1] == 138 && box_bar[loopbar_1][loopbar_2][3] == 184){
                                      box_bar[loopbar_1][loopbar_2][12] = 100;                        
                             }else{box_bar[loopbar_1][loopbar_2][12] = 11;}
                          }
                       }break;
                     case 2:
                        if(p1+46 == box_bar[loopbar_1][loopbar_2][0] && p2-46 == box_bar[loopbar_1][loopbar_2][1] && p3+46 == box_bar[loopbar_1][loopbar_2][2] && p4-46 == box_bar[loopbar_1][loopbar_2][3] ){
                          if(box_bar[loopbar_1][loopbar_2][4] == 12 || box_bar[loopbar_1][loopbar_2][4] == 22 || box_bar[loopbar_1][loopbar_2][4] == 32 ||box_bar[loopbar_1][loopbar_2][4] == 200 ){
                             box_bar[loopbar_1][loopbar_2][5] = 13;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             if(box_bar[loopbar_1][loopbar_2][1] == 138 && box_bar[loopbar_1][loopbar_2][3] == 184){
                                      box_bar[loopbar_1][loopbar_2][12] = 100;                        
                             }else{box_bar[loopbar_1][loopbar_2][12] = 11;}
                          }
                       }break;
                   }
                }else{//player 2
                    switch(i){
                     case 0:
                       if(p1 == box_bar[loopbar_1][loopbar_2][0] && p2+46 == box_bar[loopbar_1][loopbar_2][1] && p3 == box_bar[loopbar_1][loopbar_2][2] && p4+46 == box_bar[loopbar_1][loopbar_2][3] ){
                          if(box_bar[loopbar_1][loopbar_2][4] == 0){
                             box_bar[loopbar_1][loopbar_2][5] = 12;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             if(box_bar[loopbar_1][loopbar_2][1] == 276 && box_bar[loopbar_1][loopbar_2][3] == 322){
                                      box_bar[loopbar_1][loopbar_2][12] = 200;                        
                             }else{box_bar[loopbar_1][loopbar_2][12] = 12;}
                          } 
                       }break;
                     case 1:
                        if(p1-46 == box_bar[loopbar_1][loopbar_2][0] && p2+46 == box_bar[loopbar_1][loopbar_2][1] && p3-46 == box_bar[loopbar_1][loopbar_2][2] && p4+46 == box_bar[loopbar_1][loopbar_2][3] ){
                          if(box_bar[loopbar_1][loopbar_2][4] == 11 || box_bar[loopbar_1][loopbar_2][4] == 21 || box_bar[loopbar_1][loopbar_2][4] == 31 ||box_bar[loopbar_1][loopbar_2][4] == 100 ){
                             box_bar[loopbar_1][loopbar_2][5] = 13;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             if(box_bar[loopbar_1][loopbar_2][1] == 276 && box_bar[loopbar_1][loopbar_2][3] == 322){
                                      box_bar[loopbar_1][loopbar_2][12] = 200;                        
                             }else{box_bar[loopbar_1][loopbar_2][12] = 12;}
                          }
                       }break;
                     case 2:
                        if(p1+46 == box_bar[loopbar_1][loopbar_2][0] && p2+46 == box_bar[loopbar_1][loopbar_2][1] && p3+46 == box_bar[loopbar_1][loopbar_2][2] && p4+46 == box_bar[loopbar_1][loopbar_2][3] ){
                          if(box_bar[loopbar_1][loopbar_2][4] == 11 || box_bar[loopbar_1][loopbar_2][4] == 21 || box_bar[loopbar_1][loopbar_2][4] == 31 ||box_bar[loopbar_1][loopbar_2][4] == 100 ){
                             box_bar[loopbar_1][loopbar_2][5] = 13;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     if(box_bar[loopbar_1][loopbar_2][1] == 276 && box_bar[loopbar_1][loopbar_2][3] == 322){
				      box_bar[loopbar_1][loopbar_2][12] = 200;
			     }else{box_bar[loopbar_1][loopbar_2][12] = 12;}
			    }
		       }break;
		      }
		     }
	        }
	       num++;
	      }
         }
 }
 void bia(int p1,int p2,int p3,int p4,int player ,int color){
      int loopbar_1,loopbar_2,i,num = 1;
      int chip[3][4];
      for(loopbar_1 = 0; loopbar_1 <= 7; loopbar_1++){
	  for(loopbar_2 = 0; loopbar_2 <= 7; loopbar_2++){
	     for(i=0;i<4;i++){
		if(player == 100){//player 1
		   switch(i){
		     case 0:
		       if(p1-46 == box_bar[loopbar_1][loopbar_2][0] && p2+46 == box_bar[loopbar_1][loopbar_2][1] && p3-46 == box_bar[loopbar_1][loopbar_2][2] && p4+46 == box_bar[loopbar_1][loopbar_2][3] ){
			  if(box_bar[loopbar_1][loopbar_2][4] == 0){
			     box_bar[loopbar_1][loopbar_2][5] = 12;
			     box_bar[loopbar_1][loopbar_2][7] = p1;
			     box_bar[loopbar_1][loopbar_2][8] = p2;
			     box_bar[loopbar_1][loopbar_2][9] = p3;
			     box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     box_bar[loopbar_1][loopbar_2][12] = 100;}
			  if(box_bar[loopbar_1][loopbar_2][4] == 12 ||box_bar[loopbar_1][loopbar_2][4] == 22  ||box_bar[loopbar_1][loopbar_2][4] == 32 ||box_bar[loopbar_1][loopbar_2][4] == 200){
			     box_bar[loopbar_1][loopbar_2][5] = 13;
			     box_bar[loopbar_1][loopbar_2][7] = p1;
			     box_bar[loopbar_1][loopbar_2][8] = p2;
			     box_bar[loopbar_1][loopbar_2][9] = p3;
			     box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     box_bar[loopbar_1][loopbar_2][12] = 100;}
		       }break;
		     case 1:
		       if(p1+46 == box_bar[loopbar_1][loopbar_2][0] && p2+46 == box_bar[loopbar_1][loopbar_2][1] && p3+46 == box_bar[loopbar_1][loopbar_2][2] && p4+46 == box_bar[loopbar_1][loopbar_2][3] ){
			  if(box_bar[loopbar_1][loopbar_2][4] == 0){
			     box_bar[loopbar_1][loopbar_2][5] = 12;
			     box_bar[loopbar_1][loopbar_2][7] = p1;
			     box_bar[loopbar_1][loopbar_2][8] = p2;
			     box_bar[loopbar_1][loopbar_2][9] = p3;
			     box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     box_bar[loopbar_1][loopbar_2][12] = 100;}
			  if(box_bar[loopbar_1][loopbar_2][4] == 12 ||box_bar[loopbar_1][loopbar_2][4] == 22  ||box_bar[loopbar_1][loopbar_2][4] == 32 ||box_bar[loopbar_1][loopbar_2][4] == 200){
			     box_bar[loopbar_1][loopbar_2][5] = 13;
			     box_bar[loopbar_1][loopbar_2][7] = p1;
			     box_bar[loopbar_1][loopbar_2][8] = p2;
			     box_bar[loopbar_1][loopbar_2][9] = p3;
			     box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     box_bar[loopbar_1][loopbar_2][12] = 100;}
		       }break;
		     case 2:
		       if(p1+46 == box_bar[loopbar_1][loopbar_2][0] && p2-46 == box_bar[loopbar_1][loopbar_2][1] && p3+46 == box_bar[loopbar_1][loopbar_2][2] && p4-46 == box_bar[loopbar_1][loopbar_2][3] ){
			  if(box_bar[loopbar_1][loopbar_2][4] == 0){
			     box_bar[loopbar_1][loopbar_2][5] = 12;
			     box_bar[loopbar_1][loopbar_2][7] = p1;
			     box_bar[loopbar_1][loopbar_2][8] = p2;
			     box_bar[loopbar_1][loopbar_2][9] = p3;
			     box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     box_bar[loopbar_1][loopbar_2][12] = 100;}
			  if(box_bar[loopbar_1][loopbar_2][4] == 12 ||box_bar[loopbar_1][loopbar_2][4] == 22  ||box_bar[loopbar_1][loopbar_2][4] == 32 ||box_bar[loopbar_1][loopbar_2][4] == 200){
			     box_bar[loopbar_1][loopbar_2][5] = 13;
			     box_bar[loopbar_1][loopbar_2][7] = p1;
			     box_bar[loopbar_1][loopbar_2][8] = p2;
			     box_bar[loopbar_1][loopbar_2][9] = p3;
			     box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     box_bar[loopbar_1][loopbar_2][12] = 100;}
		       }break;
		       case 3:
		       if(p1-46 == box_bar[loopbar_1][loopbar_2][0] && p2-46 == box_bar[loopbar_1][loopbar_2][1] && p3-46 == box_bar[loopbar_1][loopbar_2][2] && p4-46 == box_bar[loopbar_1][loopbar_2][3] ){
			  if(box_bar[loopbar_1][loopbar_2][4] == 0){
			     box_bar[loopbar_1][loopbar_2][5] = 12;
			     box_bar[loopbar_1][loopbar_2][7] = p1;
			     box_bar[loopbar_1][loopbar_2][8] = p2;
			     box_bar[loopbar_1][loopbar_2][9] = p3;
			     box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     box_bar[loopbar_1][loopbar_2][12] = 100;}
			  if(box_bar[loopbar_1][loopbar_2][4] == 12 ||box_bar[loopbar_1][loopbar_2][4] == 22  ||box_bar[loopbar_1][loopbar_2][4] == 32 ||box_bar[loopbar_1][loopbar_2][4] == 200){
			     box_bar[loopbar_1][loopbar_2][5] = 13;
			     box_bar[loopbar_1][loopbar_2][7] = p1;
			     box_bar[loopbar_1][loopbar_2][8] = p2;
			     box_bar[loopbar_1][loopbar_2][9] = p3;
			     box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     box_bar[loopbar_1][loopbar_2][12] = 100;}
		       }break;
		   }
		}else{
		    switch(i){//player2
		      case 0:
		       if(p1-46 == box_bar[loopbar_1][loopbar_2][0] && p2+46 == box_bar[loopbar_1][loopbar_2][1] && p3-46 == box_bar[loopbar_1][loopbar_2][2] && p4+46 == box_bar[loopbar_1][loopbar_2][3] ){
			  if(box_bar[loopbar_1][loopbar_2][4] == 0){
			     box_bar[loopbar_1][loopbar_2][5] = 12;
			     box_bar[loopbar_1][loopbar_2][7] = p1;
			     box_bar[loopbar_1][loopbar_2][8] = p2;
			     box_bar[loopbar_1][loopbar_2][9] = p3;
			     box_bar[loopbar_1][loopbar_2][10] = p4;
			     box_bar[loopbar_1][loopbar_2][11] =color;
			     box_bar[loopbar_1][loopbar_2][12] = 200;}
			  if(box_bar[loopbar_1][loopbar_2][4] == 11 ||box_bar[loopbar_1][loopbar_2][4] == 21  ||box_bar[loopbar_1][loopbar_2][4] == 31 ||box_bar[loopbar_1][loopbar_2][4] == 100){
                             box_bar[loopbar_1][loopbar_2][5] = 13;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             box_bar[loopbar_1][loopbar_2][12] = 200;}
                       }break;
                     case 1:
                       if(p1+46 == box_bar[loopbar_1][loopbar_2][0] && p2+46 == box_bar[loopbar_1][loopbar_2][1] && p3+46 == box_bar[loopbar_1][loopbar_2][2] && p4+46 == box_bar[loopbar_1][loopbar_2][3] ){
                          if(box_bar[loopbar_1][loopbar_2][4] == 0){
                             box_bar[loopbar_1][loopbar_2][5] = 12;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             box_bar[loopbar_1][loopbar_2][12] = 200;}
                          if(box_bar[loopbar_1][loopbar_2][4] == 11 ||box_bar[loopbar_1][loopbar_2][4] == 21  ||box_bar[loopbar_1][loopbar_2][4] == 31 ||box_bar[loopbar_1][loopbar_2][4] == 100){   
			     box_bar[loopbar_1][loopbar_2][5]=13;
			     box_bar[loopbar_1][loopbar_2][7]=p1;
			     box_bar[loopbar_1][loopbar_2][8]=p2;
			     box_bar[loopbar_1][loopbar_2][9]=p3;
			     box_bar[loopbar_1][loopbar_2][10]=p4;
			     box_bar[loopbar_1][loopbar_2][11]=color;
			     box_bar[loopbar_1][loopbar_2][12]=200;}
                       }break;
                     case 2:
                       if(p1+46 == box_bar[loopbar_1][loopbar_2][0] && p2-46 == box_bar[loopbar_1][loopbar_2][1] && p3+46 == box_bar[loopbar_1][loopbar_2][2] && p4-46 == box_bar[loopbar_1][loopbar_2][3] ){
                          if(box_bar[loopbar_1][loopbar_2][4] == 0){
                             box_bar[loopbar_1][loopbar_2][5] = 12;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             box_bar[loopbar_1][loopbar_2][12] = 200;}
                          if(box_bar[loopbar_1][loopbar_2][4] == 11 ||box_bar[loopbar_1][loopbar_2][4] == 21  ||box_bar[loopbar_1][loopbar_2][4] == 31 ||box_bar[loopbar_1][loopbar_2][4] == 100){
                             box_bar[loopbar_1][loopbar_2][5] = 13;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             box_bar[loopbar_1][loopbar_2][12] = 200;}
                       }break;
                       case 3:
                       if(p1-46 == box_bar[loopbar_1][loopbar_2][0] && p2-46 == box_bar[loopbar_1][loopbar_2][1] && p3-46 == box_bar[loopbar_1][loopbar_2][2] && p4-46 == box_bar[loopbar_1][loopbar_2][3] ){
                          if(box_bar[loopbar_1][loopbar_2][4] == 0){
                             box_bar[loopbar_1][loopbar_2][5] = 12;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             box_bar[loopbar_1][loopbar_2][12] = 200;}
                          if(box_bar[loopbar_1][loopbar_2][4] == 11 ||box_bar[loopbar_1][loopbar_2][4] == 21  ||box_bar[loopbar_1][loopbar_2][4] == 31 ||box_bar[loopbar_1][loopbar_2][4] == 100){
                             box_bar[loopbar_1][loopbar_2][5] = 13;
                             box_bar[loopbar_1][loopbar_2][7] = p1; 
                             box_bar[loopbar_1][loopbar_2][8] = p2;
                             box_bar[loopbar_1][loopbar_2][9] = p3;
                             box_bar[loopbar_1][loopbar_2][10] = p4;
                             box_bar[loopbar_1][loopbar_2][11] =color;
                             box_bar[loopbar_1][loopbar_2][12] = 200;}
                       }break;
                   }
                }
             }
            num++;
          }
      }
}


