/*
 * Project GPS Tracking Arduino with Neobox 6
 * Author : IDNmakerspace Algorithm Factory
 * Reference : KelasRobot.com // cc ajang rahmat
 */

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

SoftwareSerial serial_gps(2, 3); 
TinyGPSPlus gps;

double latitude, longitude;

void setup() 
{
  Serial.begin(9600);
  serial_gps.begin(9600);
  Serial.println("GPS Mulai");
}

void loop() 
{
  while(serial_gps.available()) 
  {
    gps.encode(serial_gps.read());
  }
  if(gps.location.isUpdated()) 
  {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
    Serial.print("Google Maps : ");
    String link = "www.google.com/maps/place/" + String(latitude) + "," + String(longitude) ;
    Serial.println(link);
    delay(5000);
  }
}
