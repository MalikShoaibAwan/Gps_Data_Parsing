# Gps_Data_Parsing
1)In GPS folder, file named "gpsdataparsing" is a header file which contain the struct and necessary functions. main.c contain the example code which can be observed to understand working.
2)In GPS->Debug->GPS is exe file of main.c .
3)To use the functionality, first read the GPS GPGGA data which will contain 16 items seperated by comma. 
4)Then call **checksumcal** function to calculate the checksum that will be then compared with checksum from GPS GPGGA data.
5)Then call parse_gps_data which will first replace every comma with space.
6)Then sscanf function in parse_gps_data will seperate the data using spaces and shift data in the respective attribute of struct.
7)Finally calculated checksum will be compared with checksum read from data (present at end after *),
8)If program didnot detect corrupted data (checksum), gps details will be visible otherwise it will show "Data is corrupted". 



























