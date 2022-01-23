import controlP5.*;
ControlP5 cp5;

void setup() {
 size(400, 600);
 cp5 = new ControlP5(this);
 cp5.setFont(createFont("Ubuntu", 20));
 cp5.addButton("btn").setPosition(10, 10).setSize(100, 30).setLabel("button 1");
 cp5.addSlider("slider").setPosition(10, 50).setSize(180, 30).setLabel("size").setRange(0, 100).setNumberOfTickMarks(10+1);

}

void btn() {
 println("click");
}

void slider(int val) {
 println(val);
}

void draw() {
 background(120);
}

// =================================Automatic knobs insert=========================================
import controlP5.*;
COntrolP5;

void setup() {

 size(600, 400);
 cp5 = new ControlP5(this);
 cp5.addButton("btn1");
 cp5.addButton("btn2").linebreak();
 cp5.addButton("btn3");

}

void draw() {
}
//====================================================================================================
import controlP5.*;
COntrolP5;

void setup() {

 size(600, 400);
 cp5 = new ControlP5(this);
 cp5.addButton("btn1");
 cp5.addButton("btn2");
 cp5.addButton("btn3");
 
 cp5.addToggle("tgl1").linebreak();
 cp5.addSlider("sld1", 0, 10);
 cp5.addSlider("sld2", 0, 1);

}

void draw() {

}
//==================================================Добавление колеса палитры и разделение основного окна=========================================
import controlP5.*;
ControlP5 cp5;

void setup() {
  size(800, 600);             // Размер основного окна
  cp5 = new ControlP5(this);  // Инициализация
  cp5.setFont(createFont("Ubuntu", 20));

  cp5.addButton("btn").setPosition(10, 10).setSize(100, 30).setLabel("button");
  cp5.addSlider("slider").setPosition(10, 50).setSize(100, 30).setLabel("size").setRange(0, 100).setNumberOfTickMarks(10+1);

  cp5.addColorWheel("col", 10, 100, 130);
}

void btn() {
  println("click");
}

void slider(int val) {
  d = val;
}

int x = 300, y = 300, d;
color col;

void draw() {
  background(255);
  fill(110);
  rect(0, 0, 200, height);
  fill(col);
  circle(x, y, d);
}
//=====================================Выпадающий список с фигурами================================================
import controlP5.*;
ControlP5 cp5;

void setup() {
  size(800, 600);             // Размер основного окна
  cp5 = new ControlP5(this);  // Инициализация
  cp5.setFont(createFont("Ubuntu", 20));

  cp5.addButton("btn")
    .setPosition(10, 10)
    .setSize(100, 30)
    .setLabel("button");

  cp5.addSlider("slider")
    .setPosition(10, 50)
    .setSize(100, 30)
    .setLabel("size")
    .setRange(0, 100)
    .setNumberOfTickMarks(10+1);

  cp5.addColorWheel("col", 10, 100, 130);

  String list[] = {"circle", "rect", "triangle"}; // Названия в выпадающем списке 
  cp5.addScrollableList("dropdown") // Выпадающий список
    .setPosition(10, 270)
    .setSize(150, 200)      // Максимальный размер выпадающего списка
    .setBarHeight(36)       // Высота заголовка списка
    .setItemHeight(36)      // Высота выпадающего меню
    .addItems(list)         // Массив в выпадающем списке
    .close();               // Изначально находится в закрытом состоянии (по умолч. открыт)
}

void btn() {
  println("click");
}

void slider(int val) {
  d = val;
}

void dropdown(int num) {
  fig = num;
}

int x = 300, y = 300, d;
int fig = 0;
color col;

void draw() {
  background(255);
  fill(110);
  rect(0, 0, 200, height);
  fill(col);
  switch (fig) {
  case 0:
    circle(x, y, d);
    break;
  case 1:
    square(x, y, d);
    break;
  case 2:
    triangle(x, y, x+d, y+d, x+d, y-d);
    break;
  }
}
//=====================================Добавление KNOB========================================
import controlP5.*;
ControlP5 cp5;

void setup() {
  size(800, 600, P3D);             // Размер основного окна
  cp5 = new ControlP5(this);  // Инициализация
  cp5.setFont(createFont("Ubuntu", 20));

  cp5.addButton("btn")
    .setPosition(10, 10)
    .setSize(100, 30)
    .setLabel("button");

  cp5.addSlider("slider")
    .setPosition(10, 50)
    .setSize(100, 30)
    .setLabel("size")
    .setRange(0, 100)
    .setNumberOfTickMarks(10+1);

  cp5.addColorWheel("col", 10, 100, 130);

  String list[] = {"circle", "rect", "triangle"}; // Названия в выпадающем списке 
  cp5.addScrollableList("dropdown") // Выпадающий список
    .setPosition(10, 270)
    .setSize(150, 200)      // Максимальный размер выпадающего списка
    .setBarHeight(36)       // Высота заголовка списка
    .setItemHeight(36)      // Высота выпадающего меню
    .addItems(list)         // Массив в выпадающем списке
    .close();               // Изначально находится в закрытом состоянии (по умолч. открыт)

  cp5.addKnob("knob")
    .setRange(0, 360)
    .setValue(0)
    .setPosition(10, 320)
    .setRadius(50)
    .setDragDirection(Knob.HORIZONTAL)
    ;
}

void knob(int val) {
 rot = val; 
}

void btn() {
  println("click");
}

void slider(int val) {
  d = val;
}

void dropdown(int num) {
  fig = num;
}

int x = 300, y = 300, d;
int fig = 0;
int rot = 0;
color col;

void draw() {
  background(255);
  fill(110);
  rect(0, 0, 200, height);
  fill(col);
  rotateZ(radians(rot));
  switch (fig) {
  case 0:
    circle(x, y, d);
    break;
  case 1:
    square(x, y, d);
    break;
  case 2:
    triangle(x, y, x+d, y+d, x+d, y-d);
    break;
  }
  rotateZ(-radians(rot));
}
//==========================================================================================
