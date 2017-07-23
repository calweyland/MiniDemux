// LedDADR v1.0

int addr = 0;
int en = 1;
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int ondisplay = 0;

void setup() {
    pinMode(2, OUTPUT); // Logic Data A
    pinMode(3, OUTPUT); // Logic Data B
    pinMode(4, OUTPUT); // Logic Data C
    pinMode(5, OUTPUT); // Logic Data D

    pinMode(6, OUTPUT); // Chip Latch 1
    pinMode(7, OUTPUT); // Chip Latch 2
    pinMode(8, OUTPUT); // Chip Latch 3

    pinMode(9, OUTPUT); // Blanking Signal

    pinMode(10, INPUT); //up button
    pinMode(13, INPUT); //up button
    pinMode(12, INPUT); //fine up button

}

void loop() {
    if (digitalRead(10) == HIGH) { //if the up button is pressed
        addr = (addr + 1) % 512;
        en = 1;
        delay(70);
    }
    if (digitalRead(12) == HIGH) { //if the fine up button is pressed
        addr = (addr + 1) % 512;
        en = 1;
        delay(200);
    }

    if (digitalRead(13) == HIGH) {// if the down button is pressed
        addr = ((addr - 1) % 512 + 512) % 512;
        en = 1;
        delay(70);
    }

    if (en == 1) { //begin the ritual of writing to the displays
        if (ondisplay != addr) { //is the address already on the display?
            //and now some maths

            dig1 = addr/100;
            dig2 = addr%100/10;
            dig3 = addr%10;

            write_to_display(1, dig1);

            write_to_display(2, dig2);

            write_to_display(3, dig3);

            digitalWrite(9,LOW); //make sure the diaplays are actually turned on!
            deselect_all_displays();

            ondisplay = addr; //the address is now on the display
        }

    } //end the ritual of writing to the displays

}

void write_to_display(int display, int dig) {

    deselect_all_displays();

    digitalWrite(display+5, LOW);

    int pin;
    int value;
    Serial.print('writing...');
    for (int i = 0; i < 4; i++) {
        pin = i+2;

        value = bitRead(dig, i) ? HIGH : LOW;
        digitalWrite(pin, value);
    }
}

void deselect_all_displays() {
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
}
