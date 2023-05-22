#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for data types
struct GPS {
    char system[10];        // GPS system identifier (e.g., 'GP' for GPS, 'GL' for GLONASS)
    float timestamp; // Timestamp in UTC (hours, minutes, and seconds)
    double latitude;    // Latitude in DDMM.MMMMM format
    char latitudeDir;   // Latitude direction ('N' for north, 'S' for south)
    double longitude;   // Longitude in DDDMM.MMMMM format
    char longitudeDir;  // Longitude direction ('E' for east, 'W' for west)
    int quality;        // Quality indicator
    int satellites;     // Number of satellites used
    double hdop;        // Horizontal dilution of precision (HDOP)
    double altitude;    // Altitude of the GPS antenna
    char altitudeUnit;  // Unit of altitude ('M' for meters, 'F' for feet)
    double geoidalSep;  // Geoidal separation
    char geoidalSepUnit;// Unit of geoidal separation
    double correctionAge;// Age of the correction
    double correctionId;// Correction station ID
    char checksum[4];   // Checksum value
}position;

void replaceCommaWithSpace(char* str) {
    int i;
    int count=0;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] == ',' ) {
            str[i] = ' ';
            ++count;
        }
    }
    //printf("\n%d",count);
}



int Check_Checksum(char *buf, int cnt)
{
    char Character;
    int Checksum = 0;
    int i;  // loop counter

    for (i = 0; i < cnt; ++i)
    {
        Character = buf[i];
        switch (Character)
        {
            case '$':
                // Ignore the dollar sign
                break;
            case '*':
                // Stop processing before the asterisk
                i = cnt;
                continue;
            default:
                // Is this the first value for the checksum?
                if (Checksum == 0)
                {
                    // Yes. Set the checksum to the value
                    Checksum = Character;
                }
                else
                {
                    // No. XOR the checksum with this character's value
                    Checksum = Checksum ^ Character;
                }
                break;
        }
    }

    // Return the checksum
    return Checksum;
}
struct GPS Parse_gps_data(char* str){
	replaceCommaWithSpace(str);
	int ret = sscanf(str, "%s %f %lf %c %lf %c %d %d %lf %lf %c %lf %c %lf %f %3s", position.system, &position.timestamp, &position.latitude, &position.latitudeDir, &position.longitude, &position.longitudeDir, &position.quality, &position.satellites,
	    &position.hdop, &position.altitude, &position.altitudeUnit,
	    &position.geoidalSep,
	    &position.geoidalSepUnit, &position.correctionAge,
	    &position.correctionId, position.checksum);
	char *temp=position.checksum;
	++temp;
	strcpy(position.checksum,temp);
//	printf("%s\n",position.checksum);
	return position;

}
