#include <iostream>
#include <vector>

#include "permutation_random.cpp"
#include "bola.cpp"

using std::cout;
using std::endl;
using std::vector;

vector<int> insertionSort(vector<int> lista)
{
    for (size_t i = 0; i < lista.size(); i++)
    {
        int chave = lista[i];
        size_t j = i - 1;

        while (j >= 0 && lista[j] > chave)
        {
            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = chave;
    }

    return lista;
}

vector<int> contar(vector<Bola> urnaBolas, vector<int> retiradas, vector<string> cores)
{
    vector<int> contagem;
    for (size_t i = 0; i < cores.size(); i++)
    {
        contagem.push_back(0);
    }

    size_t j{0};
    for (size_t i{1}; i < urnaBolas.size()+1; i++)
    {
        if (j > retiradas.size())
        {
            break;
        }
        
        if (i == retiradas[j])
        {
            int local{-1};
            for (auto tipo : cores)
            {
                ++local;
                if (urnaBolas[i-1].cor == tipo)
                {
                    break;
                }
                
            }
            contagem[local]++;
            j++;
        }
    }

    return contagem;
}

vector<int> retirar(vector<int> urna)
{
    int quantRetiradas;
    cout << "Quantas bolas serão tiradas da urna? ";
    cin >> quantRetiradas;

    vector<int> retiradas;
    for (auto bola : urna)
    {
        retiradas.push_back(bola);

        if (retiradas.size() == quantRetiradas)
        {
            break;
        }
    }

    return retiradas;
}

void status(vector<Bola> urnaBolas, vector<string> cores, vector<int> contagemTotal)
{
    cout << "\n\n############################" << endl;
    cout << "##     STATUS DA URNA     ##" << endl;
    cout << "############################" << endl;
    cout << "Total de bolas: " << urnaBolas.size() << endl;
    cout << "Total de cores: " << cores.size() << endl;
    cout << "Quantidade por tipo:" << endl;
    for (size_t i{0}; i < cores.size(); i++)
    {
        cout << "   - " << cores[i] << ": " << contagemTotal[i] << endl;
    }
}

void resultado(vector<string> cores, vector<int> contagem)
{
    cout << "\n\n>>    BOLAS RETIRADAS    <<" << endl;
    for (size_t i{0}; i < cores.size(); i++)
    {
        cout << cores[i] << ": " << contagem[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> urna;
    vector<Bola> urnaBolas;
    vector<string> cores;

    int quantBolas{0};
    while (quantBolas < 1)
    {
        cout << "Quantas bolas terá a urna? ";
        cin >> quantBolas;
    }

    int quantCores{quantBolas + 1};
    while (quantCores > quantBolas)
    {
        cout << "Quantas bolas de cores diferentes terá a urna? ";
        cin >> quantCores;
    }

    int id{1};
    int aux_qBolas = quantBolas;
    int aux_qCores = quantCores;
    bool primeiraCor = true;
    while (aux_qBolas != 0)
    {
        string cor;
        if (primeiraCor)
        {
            cout << "Qual cor terá a(s) bola(s)? ";
            primeiraCor = false;
        }
        else
        {
            cout << "Qual será a próxima cor? ";
        }
        cin >> cor;
        cores.push_back(cor);

        int quantidade;
        if (aux_qCores > 1)
        {
            cout << "Quantas bolas terá da cor " << cor << "? ";
            cin >> quantidade;
        }
        else
        {
            quantidade = aux_qBolas;
        }

        for (size_t j{0}; j < quantidade; j++)
        {
            urna.push_back(id);
            urnaBolas.push_back(Bola(id, cor));

            id++;
        }

        aux_qBolas -= quantidade;
        aux_qCores--;
    }

    vector<int> contagemTotal = contar(urnaBolas, urna, cores);
    status(urnaBolas, cores, contagemTotal);
    cout << endl;

    urna = permutation(urna);

    vector<int> retiradas = retirar(urna);
    vector<int> ordRetiradas = insertionSort(retiradas);
    vector<int> contagem = contar(urnaBolas, ordRetiradas, cores);

    resultado(cores, contagem);

    cout << endl;
    cout << endl;
    return 0;
}
