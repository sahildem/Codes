#include <graphics.h>
#define Mx getmaxx()
#define My getmaxy()
#include <dos.h>

void dino()
{
	//Making of dinosaur on a skateboard
	circle(70,330,9);
	circle(130,330,9);
	line(55,320,145,320);
	line(105,220,140,220);
	line(105,220,105,225);
	line(140,220,140,225);
	line(100,225,105,225);
	line(140,225,145,225);
	line(145,225,145,245);
	line(130,245,145,245);
	line(130,245,130,250);
	line(130,250,140,250);
	line(140,250,140,255);
	line(125,255,140,255);
	line(100,225,100,255);
	line(100,255,95,255);
	line(95,255,95,260);
	line(95,260,90,260);
	line(90,260,90,265);
	line(90,265,85,265);
	line(85,265,85,270);
	line(85,270,80,270);
	line(80,270,80,275);
	line(80,275,70,275);
	line(70,275,70,270);
	line(70,270,65,270);
	line(65,270,65,265);
	line(65,265,60,265);
	line(60,265,60,260);
	line(60,260,55,260);
	line(55,260,55,280);
	line(55,280,60,280);
	line(60,280,60,285);
	line(60,285,65,285);
	line(65,285,65,290);
	line(65,290,70,290);
	line(70,290,70,295);
	line(70,295,75,295);
	line(75,295,75,318);
	line(75,318,90,318);
	line(90,318,90,313);
	line(90,313,85,313);
	line(85,313,85,305);
	line(85,305,90,305);
	line(90,305,90,300);
	line(90,300,95,300);
	line(95,300,95,295);
	line(95,295,100,295);
	line(100,295,100,300);
	line(100,300,105,300);
	line(105,300,105,318);
	line(105,318,120,318);
	line(120,318,120,313);
	line(120,313,115,313);
	line(115,313,115,290);
	line(115,290,120,290);
	line(120,290,120,285);
	line(120,285,125,285);
	line(125,285,125,270);
	line(125,270,135,270);
	line(135,270,135,275);
	line(135,275,140,275);
	line(140,275,140,265);
	line(140,265,125,265);
	line(125,265,125,255);
	line(110,230,118,230);
	line(110,230,110,235);
	line(118,230,118,235);
	line(110,235,118,235);
	arc(55,315,180,270,5);
	arc(145,315,270,0,5);
}
int main()
{
    int gd,gm,i=0;
    initgraph(&gd,&gm,(char*)"");
	outtextxy(Mx/2-50,My/2,"Press Any Key to start");
	getch();
    int x=Mx-20,y=Mx;
    void *left,*right,*up;
  
    dino();
    right = malloc(imagesize(55,220,145,339));
    getimage(55,220,145,339,right);
    cleardevice();
    
    dino();
    up = malloc(imagesize(55,220,145,339));
    getimage(55,220,145,339,up);
    cleardevice();
    
    dino();
    left = malloc(imagesize(55,220,145,339));
    getimage(55,220,145,339,left);
	cleardevice();
    
    void *object[2]; //Array of pointers
    while(i<3)
    {
        cleardevice();
        setcolor(WHITE);
        //obstacles
        line(580,340,580,290);
		line(600,340,600,290);
		arc(590,290,0,180,10);
        setfillstyle(1,4+i);
        floodfill(585,285,WHITE);
        object[i]=malloc(imagesize(579,280,600+i+1,340)); //dynamically allocating memory of same size as image to object[i]
        getimage(579,280,600+i+1,320,object[i]);
        i++;
	}
	int jump=0,j;
    i=0;
    while(1)
    {
    	cleardevice();
        char a[10]="";
        itoa(i,a,10); //converting integer to array and storing in a 10 = decimal value
        outtextxy(350,100,"Score = ");
        outtextxy(400,100,a);
        outtextxy(200,380,"Press space to jump");
        outtextxy(200,400,"Avoid Obstacles and score HighScore");
        if(x<=0) //for obstacles
        {
            x=Mx-20;
            y=Mx;
            j++;
            j%=3;
        }
        line(0,340,Mx,340); //Ground
        setfillstyle(3,7);
        floodfill(2,380,WHITE);
        if(GetAsyncKeyState(VK_SPACE))
        {
                jump=1;          
        }
        if(jump==1)
        {
            int p=220;
            while(p>20)
            {
                putimage(55,p,up,XOR_PUT); //Draws an image stored in the up pointer
                putimage(x,300,object[j],XOR_PUT); //object[j] determines which obstacles image to be displayed
                delay(0.3);
                putimage(55,p--,up,XOR_PUT);
                putimage(x,300,object[j],XOR_PUT); //jumping
                if(p%5==1) //speed of obstacles while the dino is in air
                {
					x-=2;
                	y-=2; 
                }
        	}
        	while(p<220)
            {
                putimage(55,p,up,XOR_PUT); //Draws an image stored in the up pointer
                putimage(x,300,object[j],XOR_PUT); //Taking down the jump
                delay(0.3);
                putimage(55,p++,up,XOR_PUT);
                putimage(x,300,object[j],XOR_PUT);
                if(p%5==1) //speed of obstacles while the dino is in air
                {
					x-=2;
                	y-=2;
                }
            }
            jump=0; //back to initial state
        }

        else
        {
            putimage(55,220,right,XOR_PUT); //Draws an image stored in the right pointer
            putimage(x,300,object[j],XOR_PUT); 
            delay(25); //obstacles delay when dino is not moving
            putimage(55,220,right,XOR_PUT);
            putimage(x,300,object[j],XOR_PUT);
            x-=10;
            y-=10;
    	}
    	if(x>=55&&y<=145&&jump==0) //collision
        {
        	cleardevice();
        	outtextxy(100,100,"Game Over");
        	outtextxy(100,150,"Your Score Was ");
        	outtextxy(210,150,a);
        	getch();
            closegraph();
        }
        i++;
    }
    return 0;
}

