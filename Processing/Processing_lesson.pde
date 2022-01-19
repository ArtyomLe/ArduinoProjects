/*
void setup() {
  size(500,300, P2D);             // Размер окна программы (P2D тип обработчика)
  surface.setLocation(50, 70);    // Позиция окна
  smooth(8);                      // Сглаживание графики (2-8)
//  noLoop();                     // Остановить цикличность
//  loop();                       // Возобновить цикличность
}

void draw() {
  println("kak");
}
*/
void setup() {
  size(600, 400, P2D);
  noStroke();
  fill(0);
}

void draw() {
  background(200);                // if disable this raw => painter
  circle(width/2, height/2, 50);  // circle(mouseX, mouseY, 50);
}

//==============================================================================================

void setup() {
  size(600, 400, P2D);
  smooth(8);
  frameRate(300);
  noStroke();
  fill(0);

}

void draw() {
  if (mousePressed == true) circle(mouseX, mouseY, 10); // Paint only if mouse button is pressed
}
//=================================PAIN-ERASE========================================

void setup() {

 size(600, 400,P2D);
 smooth(8);
 frameRate(300);
 noStroke();
 fill(0);
 background(200);
}

void draw() {

 if (mousePressed == true) {
  switch (mouseButton) {
  
   case LEFT: fill(0);
    break;

   case RIGHT: fill(200);
    break;
  }
  circle(mouseX, mouseY, 10);
 }
}
//=======================================PAIN-ERASE-ZOOMING=======================================================
void setup() {

 size(600, 400,P2D);
 smooth(8);
 frameRate(300);
 noStroke();
 fill(0);
 background(200);
}

float size = 10;

void draw() {

 if (mousePressed == true) {
  switch (mouseButton) {
  
   case LEFT: fill(0);
    break;

   case RIGHT: fill(200);
    break;
  }
  circle(mouseX, mouseY, size);
 }
}

void mouseWheel(MouseEvent event) {
  size += event.getCount();
  size = constrain(size, 0, 100);     // constrain zooming (0 - 100)
}
//===================================================================
