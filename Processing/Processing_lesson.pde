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
//=================================Управление с клавиатуры==================================
void setup() {

  size(600, 400, P2D);
  smooth(8);
  noStroke();
  fill(20);
}

int x = 300, y = 200;
int shift = 5;

void draw() {
  background(200);
  if (keyPressed == true) {
    switch(keyCode) {
    case UP: 
      y -= shift;
      break;
    case DOWN: 
      y += shift;
      break;
    case LEFT: 
      x -= shift;
      break;
    case RIGHT: 
      x += shift;
      break;
    }
  }
  circle(x, y, 50);
}
//=====================================================COLOR================================
void setup() {

  size(600, 400, P2D);
  smooth(8);
  noStroke();
  colorMode(HSB, 255, 255, 255);
}

int col = 0;

void draw() {
  background(200);
  col++;
  if (col > 255) col = 0;
  fill(col, 255, 255); // максимальная насыщенность, максимальная яркость
  circle(width/2, height/2, 150);
}
//===================================Плавное следование шарика аз курсором мыши(алгоритм запаздывания)================
void setup() {

  size(600, 400, P2D);
  smooth(8);
  noStroke();
  colorMode(HSB, 255, 255, 255);
}

int col = 0;
float x = 300, y = 200;
void draw() {
  background(200);
  if (++col > 255) col = 0;
  fill(col, 255, 255);       // максимальная насыщенность, максимальная яркость
  
  // Запаздывающий фильтр (экспоненциально бегущая средняя)
  x += (mouseX - x) * 0.08;   // Коэффициентом меняем скорость следования шарика
  y += (mouseY - y) * 0.08;
  
  circle(x, y, 50);
//================================Один отскакивающий шарик=========================================
void setup() {

  size(600, 400, P2D);
  smooth(8);
  noStroke();
  fill(255, 0, 0);
}


float x = 300, y = 200;
float velX = 3.5, velY = 7;
int R = 25;
void draw() {
  background(200);
  
  x += velX;
  y += velY;
  
  if (x < R || x > width - R) velX = -velX;
  if (y < R || y > height - R) velY = -velY;
  
  circle(x, y, (R*2));
}
//===================================================================
