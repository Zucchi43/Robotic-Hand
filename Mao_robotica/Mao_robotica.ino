#include <Servo.h>

int maximo1 = 0;
int minimo1 = 1024;
int maximo2 = 0;
int minimo2 = 1024;
int maximo3 = 0;
int minimo3 = 1024;
int maximo4 = 0;
int minimo4 = 1024;
int maximo5 = 0;
int minimo5 = 1024;




int val_sensor;
int amostras = 50;

int output_f =0;;
int output;
 int outputs1[50 ];
 int outputs2[50 ];
 int outputs3[50 ];
 int outputs4[50 ];
 int outputs5[50 ];

 
Servo Polegar;
Servo Indicador;
Servo Medio;
Servo Anelar;
Servo Mindinho;
void setup(){
//A3 e 
 Polegar.attach(3);
 Indicador.attach(5);
 Medio.attach(6);
 Anelar.attach(9);
 Mindinho.attach(10);
 Serial.begin(9600);

}

void loop(){
  
  //SENSOR 1 - POLEGAR
    val_sensor = analogRead(A0);
    if(val_sensor < 1023 && val_sensor > 500){
    if (val_sensor > maximo1){
      maximo1 = val_sensor;
    }
    if (val_sensor < minimo1){
      minimo1 = val_sensor;
    }
    output = map (val_sensor, minimo1, maximo1, 0, 300);
   // Serial.println(output);


for(int i =0; i<amostras-1; i++){
  outputs1[i] = outputs1[i+1];
}
outputs1[amostras-1]=output;
output_f=0;
for(int i =0; i<amostras; i++){
  output_f += outputs1[i]; 
}
output_f = output_f/amostras;
output_f = output_f/20;
output_f = output_f*20;
  Serial.println(output_f);
 
  //Polegar.write(output_f);
  Polegar.write(map(output_f, 0, 100, 0, 250));
    }


//SENSOR 2 - iNDICADOR
    val_sensor = analogRead(A1);
    if(val_sensor != 1023 && val_sensor !=0){
    if (val_sensor > maximo2){
      maximo2 = val_sensor;
    }
    if (val_sensor < minimo2){
      minimo2 = val_sensor;
    }
    output = map (val_sensor, minimo2, maximo2, 0, 180);
    //Serial.println(output);

    


for(int i =0; i<amostras-1; i++){
  outputs2[i] = outputs2[i+1];
}
outputs2[amostras-1]=output;
output_f=0;
for(int i =0; i<amostras; i++){
  output_f += outputs2[i];
}
output_f = output_f/amostras;
output_f = output_f/20;
output_f = output_f*20;
  //Serial.println(output_f);
  //Indicador.write(output_f);
  Indicador.write(map(output_f, 60, 140, 0, 250));
    }






//SENSOR 3 - MEDIO
    val_sensor = analogRead(A2);
    if(val_sensor != 1023){
    if (val_sensor > maximo3){
      maximo3 = val_sensor;
    }
    if (val_sensor < minimo3){
      minimo3 = val_sensor;
    }
    output = map (val_sensor, minimo3, maximo3, 0, 180);
   // Serial.println(output);

    


for(int i =0; i<amostras-1; i++){
  outputs3[i] = outputs3[i+1];
}
outputs3[amostras-1]=output;
output_f=0;
for(int i =0; i<amostras; i++){
  output_f += outputs3[i];
}
output_f = output_f/amostras;
output_f = output_f/20;
output_f = output_f*20;
  //Serial.println(output_f);
  //Medio.write(output_f);
  Medio.write(map(output_f, 80, 130, 0, 250));
    }








    //SENSOR 4 - ANELAR
    val_sensor = analogRead(A3);
    if(val_sensor != 1023){
    if (val_sensor > maximo4){
      maximo4 = val_sensor;
    }
    if (val_sensor < minimo4){
      minimo4 = val_sensor;
    }
    output = map (val_sensor, minimo4, maximo4, 0, 180);
   // Serial.println(output);

    


for(int i =0; i<amostras-1; i++){
  outputs4[i] = outputs4[i+1];
}
outputs4[amostras-1]=output;
output_f=0;
for(int i =0; i<amostras; i++){
  output_f += outputs4[i];
}
output_f = output_f/amostras;
output_f = output_f/20;
output_f = output_f*20;
  //Serial.println(output_f);
  //Anelar.write(output_f);
  Anelar.write(map(output_f, 60, 160, 0, 180));
    }




  //SENSOR 5 - MINDINHO
    val_sensor = analogRead(A4);
    if(val_sensor != 1023){
    if (val_sensor > maximo5){
      maximo5 = val_sensor;
    }
    if (val_sensor < minimo5){
      minimo5 = val_sensor;
    }
    output = map (val_sensor, minimo5, maximo5, 180, 0);
   // Serial.println(output);

    


for(int i =0; i<amostras-1; i++){
  outputs5[i] = outputs5[i+1];
}
outputs5[amostras-1]=output;
output_f=0;
for(int i =0; i<amostras; i++){
  output_f += outputs5[i];
}
output_f = output_f/amostras;
output_f = output_f/20;
output_f = output_f*10;
  //Serial.println(output_f);
  //Mindinho.write(output_f);
  Mindinho.write(map(output_f, 70, 80, 0, 180));
    }
    delay(10);
  }
