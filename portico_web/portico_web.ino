#include <ESP8266WiFi.h> 
WiFiServer server(80); 
WiFiClient client; 
int val; 
const char index_html[] = R"rawliteral( 
HTTP/1.1 200 OK 
Content-Type: text/html 
<!DOCTYPE html>
<html>
<head>
  <title>Controlo de Movimento do Portico</title>
  <style>
    .meu-botao {
      background-color: #79a832;
      border: normal;
      color: black;
      padding: 16px 32px;
      text-align: center;
      text-decoration: normal;
      display: inline-block;
      font-size: 24px;
      margin: 4px 2px;
      cursor: pointer;
    }

    #zerar-btn {
      background-color: blue; /* Altera a cor para azul */
    }

    #parar-btn {
      background-color: red; /* Altera a cor para vermelho */
    }
  </style>
</head>
<body background="C:\xampp\htdocs\render portico 2.JPG">
   
  <h1>Controlo de Movimento do Portico</h1>

  <button id="zerar-btn" class="meu-botao" onclick="zerar()">Zerar</button> <br><br><br>
  <button id="modo-btn" class="meu-botao" onclick="toggleModo()">Modo Manual</button> <br> <br>
  <button id="posicionamento-automatico-btn" class="meu-botao" onclick="posicionamentoAutomatico()">Posicionamento automático</button>
  <br><br>
  <button id="ciclo-btn" class="meu-botao" onclick="executarCiclo()">Ciclo</button>
  <br><br><br><br><br>

  <button id="velocidade-lenta-btn" class="meu-botao" onclick="definirVelocidade('lenta')">Velocidade lenta</button>
  <button id="velocidade-media-btn" class="meu-botao" onclick="definirVelocidade('media')">Velocidade média</button>
  <button id="velocidade-alta-btn" class="meu-botao" onclick="definirVelocidade('alta')">Velocidade alta</button>
  <br><br><br><br><br>

  <button id="horario-btn" class="meu-botao" onclick="moverHorario()">Botão Horário</button>
  <button id="parar-btn" class="meu-botao" onclick="parar()">Parar</button>
  <button id="anti-horario-btn" class="meu-botao" onclick="moverAntiHorario()">Botão Anti-Horário</button>
  
  <script>
    
  </script>
</body>
</html>)rawliteral"; 
void setup() { 
// Inicia o objecto Rs232 
Serial.begin(9600); 
// Pede ligação WiFi, ao Router 
WiFi.begin("Redmi Note 9S","xxxxxxx"); 
// espera que o Router aceite a ligação WiFi 
while(WiFi.status() != WL_CONNECTED ) { delay(500); Serial.print("."); } 
Serial.println("ESP connecto to router , by Wifi"); 
// ativa o servidor TCP/IP 
server.begin(); 
Serial.println("Servidor TCPIP ativo"); 
// IP address 
Serial.println(WiFi.localIP()); 
 
} // Setup() 
void loop() { 
 // Espera que o Browser peça ligação TCP/IP 
 client = server.available(); 
// Se chegou uma ligação TCPIP 
if (client.connected()){ 
 Serial.println("nova ligação TCPIP \r\n"); 
 } 
// Se o Browser enviou dados , ex. GET index.html 
 if(client.available()){ 

} // Loop 