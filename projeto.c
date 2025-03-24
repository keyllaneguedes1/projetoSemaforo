#include "pico/stdlib.h"

#define LED_VERDE  13
#define LED_AMARELO 12
#define LED_VERMELHO 11
#define BOTAO 5

bool sistema_ligado = false;

void setup() {
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);
}

void semaforo() {
    // Verde ligado por 5 segundos
    gpio_put(LED_VERDE, 1);
    sleep_ms(5000);
    gpio_put(LED_VERDE, 0);

    // Amarelo ligado por 2 segundos
    gpio_put(LED_AMARELO, 1);
    sleep_ms(2000);
    gpio_put(LED_AMARELO, 0);

    // Vermelho ligado por 5 segundos
    gpio_put(LED_VERMELHO, 1);
    sleep_ms(5000);
    gpio_put(LED_VERMELHO, 0);
}

int main() {
    stdio_init_all();
    setup();

    while (1) {
        if (!gpio_get(BOTAO)) {
            sleep_ms(200); // Debounce
            if (!gpio_get(BOTAO)) {
                sistema_ligado = !sistema_ligado;
                while (!gpio_get(BOTAO)); // Espera soltar o botão
            }
        }

        if (sistema_ligado) {
            semaforo();
        } else {
            gpio_put(LED_VERDE, 0);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERMELHO, 0);
        }
    }

    return 0;
}
