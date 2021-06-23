/* Implemente uma classe Carro. O tanque de combustível do carro armazena no máximo 50 litros de gasolina. O carro consome 15 km/litro. Deve ser possível:
 - Abastecer o carro com uma certa quantidade de gasolina;
 - Mover o carro em uma determinada distância (medida em km);
 - Retornar a quantidade de combustível restante e a distância total percorrida.

    No programa principal, crie 2 carros. Abasteça 20 litros no primeiro e 30 litros no segundo. Desloque o primeiro em 200 km e o segundo em 400 km. Exiba na tela a distância percorrida e o total de combustível restante para cada um.
*/

#include<iostream>

using namespace std;

class Carro{
    private:
        float tanque;
        int consumo;
        int distancia;
    public:
        Carro(){ }
        Carro(float tanque, int consumo){
            this->tanque = tanque;
            this->consumo = consumo;
            this->distancia = 0;
        }
        void abastecer(float litros){
            this->tanque += litros;
        }
        void mover(int km){
            this->distancia += km;
            float litros = km/consumo;
            this->tanque = this->tanque - litros;
        }
        void printStatus(){
            cout<<"Tanque: "<<tanque<<"\t Distancia: "<<distancia<<" km"<<endl;
        }
};

class Fusca:public Carro{
    public:
        Fusca(){}
        Fusca(float tanque):Carro(tanque, 12){}
};

class Ferrari:public Carro{
    private:
        bool bluetooth;
    public:
        Ferrari(){}
        Ferrari(float tanque):Carro(tanque, 6){
        }
        void ligarBluetooth(){
            this->bluetooth = true;
        }
};

int main(){
    Fusca f1(20);
    Ferrari f2(30);

    f1.mover(200);
    f2.mover(400);

    f1.printStatus();
    f2.printStatus();
    
    f2.ligarBluetooth();

    return 0;
}
