
char ble_val;                        // char variable, save the value of bluetooth reception

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (serial.available() > 0)     // judge if there is data in serail buffer
    {
        ble_val = Serial.read();    // read data from serial buffer
        Serial.println(ble_val);    // print the data
    }
}