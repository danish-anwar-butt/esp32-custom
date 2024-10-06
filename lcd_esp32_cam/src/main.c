#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "ssd1306.h"
#include "font8x8_basic.h"

 
 #define CONFIG_SDA_GPIO 2
 #define CONFIG_SCL_GPIO 16
 #define CONFIG_RESET_GPIO 33
#define FLASH_PIN 4 

#define tag "SSD1306"

void app_main(void)
{
	SSD1306_t dev;
	int center, top, bottom;
	char lineChar[20];

	ESP_LOGI(tag, "INTERFACE is i2c");
	ESP_LOGI(tag, "CONFIG_SDA_GPIO=%d",CONFIG_SDA_GPIO);
	ESP_LOGI(tag, "CONFIG_SCL_GPIO=%d",CONFIG_SCL_GPIO);
	ESP_LOGI(tag, "CONFIG_RESET_GPIO=%d",CONFIG_RESET_GPIO);
	i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);

	    // Configure the GPIO pin as an output
    gpio_set_direction(FLASH_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(FLASH_PIN, 0);

	ESP_LOGI(tag, "Panel is 128x32");
	ssd1306_init(&dev, 128, 32);

	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);
	ssd1306_display_text_x3(&dev, 0, "Nano", 9, false);
	vTaskDelay(3000 / portTICK_PERIOD_MS);

	top = 1;
	center = 1;
	bottom = 4;


	// Horizontal Scroll
	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);
	ssd1306_display_text(&dev, center, "Ayesha", 8, false);
	ssd1306_hardware_scroll(&dev, SCROLL_RIGHT);
	vTaskDelay(5000 / portTICK_PERIOD_MS);
	ssd1306_hardware_scroll(&dev, SCROLL_LEFT);
	vTaskDelay(5000 / portTICK_PERIOD_MS);
	ssd1306_hardware_scroll(&dev, SCROLL_STOP);
	
	// Vertical Scroll
	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);
	ssd1306_display_text(&dev, center, "Hassan Hussain", 16, false);
	ssd1306_hardware_scroll(&dev, SCROLL_DOWN);
	vTaskDelay(10000 / portTICK_PERIOD_MS);
	ssd1306_hardware_scroll(&dev, SCROLL_UP);
	vTaskDelay(10000 / portTICK_PERIOD_MS);
	ssd1306_hardware_scroll(&dev, SCROLL_STOP);
	
	// Invert
	ssd1306_clear_screen(&dev, true);
	ssd1306_contrast(&dev, 0xff);
	ssd1306_display_text(&dev, center, "  Good Bye!!", 12, true);
	vTaskDelay(5000 / portTICK_PERIOD_MS);


	// Fade Out
	ssd1306_fadeout(&dev);
	
#if 0
	// Fade Out
	for(int contrast=0xff;contrast>0;contrast=contrast-0x20) {
		ssd1306_contrast(&dev, contrast);
		vTaskDelay(40);
	}
#endif

	// Restart module
	esp_restart();
}