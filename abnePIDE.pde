int state=-1;
int rposx=300;
int rposy=150;
int posx[],posy[];
int i,j,k;
int score;
void setup()
{
  size(800,300);
  posx=new int[1000];
  posy=new int[1000];
  for(i=0;i<1000;++i)
  {
  posx[i]=int(random(10000))+500;
  posy[i]=int(random(300));
  }
}
void draw()
{
  background(0);
  if(state==-1)
  {
  fill(0,100,200);
  textSize(32);
  text("ABNE",100,50);
  text("Press any key to start...",300,150);
  textSize(20);
  text("W:UP\nS:DOWN",100,200);
  score=0;
  }
  else
  {
  fill(0,200,100);
  rect(rposx,rposy,20,20,3);
  for(i=0;i<1000;++i)
  {
  posx[i]--;
  fill(255,255,255);
  textSize(20);
  text(score,20,250);
  if(posx[i]>=0&&posx[i]<=800)
  {fill(200,0,0);ellipse(posx[i],posy[i],10,10);}
  if(posx[i]<0){posx[i]=int(random(10000))+500;}
  for(j=5;j<15;++j)
  for(k=5;k<15;++k)
  {if(red(get(rposx+j,rposy+k))==200){state=-1;}}
  if(state==-1)
  {
  for(i=0;i<1000;++i){posx[i]=int(random(10000))+500;}
  rposx=300;rposy=150;
  delay(2000);break;
  }
  }
  ++score;
  }
}
void keyPressed()
{
 if(state==-1){state=0;}
else if(key==CODED)
  {if(keyCode==UP){if(rposy>=5){rposy-=5;}}
 else if(keyCode==DOWN){if(rposy<=295){rposy+=5;}}}
else
{if(key=='w'||key=='W'){if(rposy>=5){rposy-=5;}}
else if(key=='s'||key=='S'){if(rposy<=295){rposy+=5;}}}
}
