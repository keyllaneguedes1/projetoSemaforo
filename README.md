# Sistema de Semáforo para Trânsito usando a Placa BitDogLab
1. Objetivos do projeto:
O objetivo deste projeto é simular o funcionamento de um sistema de semáforo para controle de trânsito, utilizando a placa BitDogLab e seus componentes (LEDs e botão). O sistema permite ligar e desligar o semáforo através de um botão, alternando entre os estados verde, amarelo e vermelho, de acordo com os tempos padrões de sinalização.

2. Descrição do funcionamento:

O sistema inicia com todos os LEDs desligados. Ao pressionar o botão, o sistema é ativado e os LEDs do semáforo começam a alternar entre as cores:
LED Verde: ligado por 5 segundos
LED Amarelo: ligado por 2 segundos
LED Vermelho: ligado por 5 segundos
Pressionando novamente o botão, o sistema é desligado, apagando todos os LEDs. O projeto se justifica como uma aplicação didática para o ensino de eletrônica e programação embarcada. Ele simula um sistema real de controle de trânsito, auxiliando na compreensão de conceitos como controle de GPIOs, debounce de botão e estrutura de loops em C para o Raspberry Pi Pico.

3. Especificação do Hardware
Descrição dos componentes eletrônicos utilizados: Placa BitDogLab (baseada no Raspberry Pi Pico), 3 LEDs (verde, amarelo e vermelho), 1 Botão de controle
Pinagem usada:
Componente
Pino do Raspberry Pi Pico
Função
LED Verde
GPIO 13
Indicar "Siga" (verde)
LED Amarelo
GPIO 12
Indicar "Atenção" (amarelo), usado o led de cor azul na placa pois o led utilizado não possui a cor amarela
LED Vermelho
GPIO 11
Indicar "Pare" (vermelho)
Botão
GPIO 5
Ligar/desligar o sistema

