# include <stdio.h>

int main() {
    char input_scale, target_scale;
    float input_temperature, c_temperature, target_temperature;

    printf("Enter the temparture value: ");
    getchar("%f", &input_temperature);

    printf("Input the original scale (C, F, or K): ");
    getchar("%c", &input_scale);

    printf("Input the scale to convert (C, F, or K): ");
    getchar("%c", &target_scale);

    if (input_scale == 'F') c_temperature = (input_temperature - 32.0) / 1.8;
    if (input_scale == 'C') c_temperature = input_temperature;
    if (input_scale == 'K') c_temperature = input_temperature - 273.15;

    if (target_scale == 'F') target_temperature = c_temperature * 1.8 + 32;
    if (target_scale == 'C') target_temperature = c_temperature;
    if (target_scale == 'F') target_temperature = c_temperature + 273.15;

    printf("Converted temperature: %f %c", target_temperature, target_scale);

    if (c_temperature < 0) {
        printf("Temperature Category: Freezing");
        printf("Weather Advisory: Wear a coat");
    }

    else if (c_temperature < 10) {
        printf("Temperature Category: Cold");
        printf("Weather Advisory: Wear a jacket");
    }

    else if (c_temperature < 25) {
        printf("Temperature Category: Comfortable");
        printf("Weather Advisory: Take a nice stroll");
    }

    else if (c_temperature < 35) {
        printf("Temperature Category: Hot");
        printf("Weather Advisory: Drink lots of water!");
    }

    else {
        printf("Temperature Category: Extreme Heat");
        printf("Weather Advisory: Stay inside!");
    }

}