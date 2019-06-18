
int ph_level = 0; //0-14
int water_level = 0; //0-100
int soil_moisture_level = 0; //0-100

void setup() {

}

void loop() {
  check_water_level();
  check_soil_moisture();
  checkPH();
}


void check_water_level() {
  if (water_level <= 40) {
    //Turn LED on
  } else {
    //Turn LED off
  }
}


void check_soil_moisture() {
  if (soil_moisture_level <= 30) {
    //Activate pump to water the plant
  }
}


void checkPH() {
  if (ph_level < 6) {
    //Add some solution to increase PH
    
  } else if (ph_level > 8) {
    //Add some solution to decrease PH
    
  } 
}
