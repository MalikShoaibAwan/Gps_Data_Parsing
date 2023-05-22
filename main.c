#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"gpsdataparsing.h"


int main() {
    struct GPS GpsD;
	char str[] = "$GPGGA,181908.00,3404.7041778,N,07044.3966270,W,4,13,1.00,495.144,M,29.200,M,0.10,0000,*73";

    char checksumcal = Check_Checksum(str,strlen(str));
    GpsD=Parse_gps_data(str);
    char hexval[6];
    sprintf(hexval,"%x",checksumcal);
    
    
    if(strcmp(hexval,GpsD.checksum)==0){
    	printf("System: %s\n", GpsD.system);
    	        printf("Timestamp: %f\n", GpsD.timestamp);
    	        printf("Latitude: %.7f %c\n", GpsD.latitude, GpsD.latitudeDir);
    	        printf("Longitude: %.7f %c\n", GpsD.longitude, GpsD.longitudeDir);
    	        printf("Quality: %d\n", GpsD.quality);
    	        printf("Satellites: %d\n", GpsD.satellites);
    	        printf("HDOP: %.2f\n", GpsD.hdop);
    	        printf("Altitude: %.3f %c\n", GpsD.altitude, GpsD.altitudeUnit);
    	        printf("Geoidal Separation: %.3f %c\n", GpsD.geoidalSep, GpsD.geoidalSepUnit);
    	        printf("Correction Age: %.2f\n", GpsD.correctionAge);
    	        printf("Correction ID: %f\n", GpsD.correctionId);
    	        printf("Checksum: %s\n", GpsD.checksum);
    	        getch();
    }else{

    	printf("Checksum error!");
    	getch();
    }
}
