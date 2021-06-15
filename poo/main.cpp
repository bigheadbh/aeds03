#include<iostream>
using namespace std;

class Retangulo {
    private:
        int largura;
        int altura;

    public:
        Retangulo(){
            this->largura = 0;
            this->altura = 0;
        }
        Retangulo(int largura, int altura){
            this->altura = altura;
            this->largura = largura;
        }
        void setLargura(int largura){
            this->largura = largura;
        }
        void setAltura(int altura){
            this->altura = altura;
        }
        int getLargura(){
            return this->largura;
        }
        int getAltura(){
            return this->altura;
        }

        int area(){
            return altura * largura;
        }
        int perimetro(){
            return 2 * (altura + largura);
        }
};

class Pessoa {
    private:
        string nome;
        int idade;
        float altura;
    public:
        Pessoa(){
            nome = "";
            idade = 0;
            altura = 0;
        }
        void setNome(string nome){
            this->nome = nome;
        }
        void setIdade(int idade){
            this->idade = idade;
        }
        void setAltura(float altura){
            this->altura = altura;
        }
        string getNome(){
            return nome;
        }
        int getIdade(){
            return idade;
        }
        float getAltura(){
            return altura;
        }
        void mostrar(){
            cout<<nome<<"\t"<<idade<<"\t"<<altura<<endl;
        }
};

int main(){
    Retangulo r1(10,20);
    cout << r1.area() <<endl;
    return 0;
}
