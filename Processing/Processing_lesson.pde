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
int R = 25;                    // Отскакиваение шарика                

void draw() {
  background(200);
  
  // Интегрируем (вводим) скорость
  x += velX;
  y += velY;
  
  // Алгоритм отскакивания шарика
  if (x < R || x > width - R) velX = -velX;
  if (y < R || y > height - R) velY = -velY;
  
  circle(x, y, (R*2));
}
//============================МАССИВ ШАРИКОВ В ДВИЖЕНИИ==================================

int amount = 5;                       // Общее кол-во шариков

float x[] = new float[amount];
float y[] = new float[amount];
float velX[] = new float[amount];
float velY[] = new float[amount];
float R[] = new float[amount];


void setup() {

  size(600, 400, P2D);
  smooth(8);
  noStroke();
  fill(255, 0, 0);

  for (int i=0; i<amount; i++) {
    R[i] = random(5, 25);               // Каждый из 5 шариков будет иметь рандомный размер
    x[i] = random(R[i], width - R[i]);  // Случайная горизонтальная координата появления каждого шара(от радиуса шара до ширины экрана)
    y[i] = random(R[i], height - R[i]); // Случайная вертикальная координата появления каждого шара(от радиуса шара до высоты экрана)

    // Генерируем случайную скорость с различным изначальным направлением движения(влево\вправо, вверх\вниз)
    velX[i] = random(3, 10) * ((int)random(0, 2) == 0 ? 1:-1); 
    velY[i] = random(3, 10) * ((int)random(0, 2) == 0 ? 1:-1);
  }
}

void draw() {

  background(200);

  // Создаём цикл для того чтобы задействовать все шарики
  for (int i = 0; i < amount; i++) {
    x[i] += velX[i];
    y[i] += velY[i];

    // В случае соприкосновения со стенкой менять направление движения
    if (x[i] < R[i] || x[i] > width - R[i]) velX[i] = -velX[i];
    if (y[i] < R[i] || y[i] > height - R[i]) velY[i] = -velY[i];

    // Прорисовываем каждый шарик
    circle(x[i], y[i], R[i]*2);
  }
}
//======================================МАССИВ ШАРОВ В ДВИЖЕНИИ С СЛУЧАЙНЫМИ ЦВЕТАМИ================================

int amount = 5;                       // Общее кол-во шариков

float x[] = new float[amount];
float y[] = new float[amount];
float velX[] = new float[amount];
float velY[] = new float[amount];
float R[] = new float[amount];

color col[] = new color[amount];     // Создаём массив цвета 

void setup() {

  size(600, 400, P2D);
  smooth(8);
  noStroke();

  for (int i=0; i<amount; i++) {
    R[i] = random(5, 25);               // Каждый из 5 шариков будет иметь рандомный размер
    x[i] = random(R[i], width - R[i]);  // Случайная горизонтальная координата появления каждого шара(от радиуса шара до ширины экрана)
    y[i] = random(R[i], height - R[i]); // Случайная вертикальная координата появления каждого шара(от радиуса шара до высоты экрана)

    // Генерируем случайную скорость с различным изначальным направлением движения(влево\вправо, вверх\вниз)
    velX[i] = random(3, 10) * ((int)random(0, 2) == 0 ? 1:-1); 
    velY[i] = random(3, 10) * ((int)random(0, 2) == 0 ? 1:-1);
    
    // Генерируем случайные цвета для шаров
    col[i] = color(random(0, 255), random(0, 255), random(0, 255));
  }
}

void draw() {

  background(200);

  // Создаём цикл для того чтобы задействовать все шарики
  for (int i = 0; i < amount; i++) {
    x[i] += velX[i];
    y[i] += velY[i];

    // В случае соприкосновения со стенкой менять направление движения
    if (x[i] < R[i] || x[i] > width - R[i]) velX[i] = -velX[i];
    if (y[i] < R[i] || y[i] > height - R[i]) velY[i] = -velY[i];

    // Генерируем случайные цвета для шаров 
    fill(col[i]);
    
    // Прорисовываем каждый шарик
    circle(x[i], y[i], R[i]*2);
  }
}
//==================================При отскоке меняем цвет на случайный========================================

