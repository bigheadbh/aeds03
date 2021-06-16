#include<iostream>
using namespace std;

#define TAM 10

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

void menu(){
    system("cls||clear");
    cout<< " 1 - Para cadastrar pessoa"<<endl;
    cout<< " 2 - Mostrar pessoas cadastradas"<<endl;
    cout<< " 3 - Para sair..."<<endl;
}

int main(){
    Pessoa pessoas[TAM];
    int count = 0;
    int opcao, idade;
    string nome;
    float altura;
    menu();
    cin>>opcao;

    while(opcao != 3){
        switch (opcao){
            case 1:
                if(count < TAM){
                    system("cls||clear");
                    cout<<"informe um nome para cadastro: "<<endl;
                    cin>>nome; cin.ignore();
                    cout<<"informe a altura da pessoa: "<<endl;
                    cin>>altura; cin.ignore();
                    cout<<"informe a idade da pessoa: "<<endl;
                    cin>>idade; cin.ignore();
                    pessoas[count].setNome(nome);
                    pessoas[count].setIdade(idade);
                    pessoas[count].setAltura(altura);
                    count ++;
                } else {
                    cout<<"Limite de cadastro alcançado...."<<endl;
                }
                getchar();
                break;
            case 2:
                for(int i = 0; i < count; i++)
                    pessoas[i].mostrar();
                getchar();
                break;
        }
        menu();
        cin>>opcao; cin.ignore();
    }
    return 0;
}
