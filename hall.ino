int hallsayac=0;
unsigned long birimyol=28035;//0,02803571429*1.000.000 birimyolu 1.000.000 ile çaptım
unsigned long hiz=0;
unsigned long sonhiz=0;
unsigned long zaman=0;
unsigned long aldigiyol=0;
unsigned long yenizaman=0,eskizaman=0,fark=0;
unsigned long sayam =0;

void setup() {
  Serial.begin(9600);
   attachInterrupt(0, sayac, CHANGE);
  
}
void sayac()
{
  micros();
  hallsayac++; 
  //Serial.println(hallsayac);
  
  
  if(hallsayac==56)
  {
    sayam++;
   aldigiyol=birimyol*hallsayac;

    yenizaman=micros();
    fark=yenizaman-eskizaman;
    eskizaman=yenizaman;   
    zaman=fark*10;// saate çevirdiğimde 10000 ile çarpmam gerekiyor
    hiz=aldigiyol*36;//km çevirdiğimide 36 ile çarpmam gerkeiyor
    sonhiz=hiz/zaman;
    hallsayac=0;
    aldigiyol=0;
    if(sayam==10)
    {
      Serial.print("hız :");
      Serial.println(sonhiz);
      sayam=0;
    }
  }
  

  
}

void loop() {
//  sayam = sayam + 1;
// if(sayam==50000 ){
//  Serial.println(sonhiz);
//  sayam = 0;
 }
  
