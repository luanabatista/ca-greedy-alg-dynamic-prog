/* UNIVERSIDADE FEDERAL DO SUL E SUDESTE DO PARÁ
   DISCIPLINA: COMPLEXIDADE DE ALGORITMOS
   PROFESSOR: MANOEL RIBEIRO
   ALUNOS: JOSÉ ARTHUR E LUANA BATISTA
   
   DEFINIÇÃO DO PROBLEMA:
   Em uma loja de doces existem N tipos de doce e o cliente tem acesso

   Em uma loja de doces com N tipos de doce o cliente observa o preço 
   de cada um.
   Nela ocorre uma promoçaão, na compra de de 1 doce você cada K 
   outros doces (de tipos diferentes) de graça.

   Agora você tem que responder duas perguntas. 
   1 - Qual a quantidade mínima de dinheiro que você tem que gastar 
       para obter todos os N tipos de doce?
   2 - Qual a quantidade máxima de dinheiro que você gastaria para 
       obter todos os N tipos de doce?

   Para os dois casos se aplica a condição da promoção de que na compra 
   de 1 você ganha K doces.

   SOLUÇÃO:
   O algoritmo a seguir é uma solução gulosa para o problema.

   RESTRIÇÕES:      
   1 <= T(num de testes) <= 50
   1 <= N(num tipos de doce) <= 1000
   0 <= K(doces ganho na promo) <= N-1
   1 <= Ai <= 100
 
   COMPLEXIDADE DE TEMPO: O(nlogn)
*/
 

 #include <bits/stdc++.h>
 #include <locale.h>
 
using namespace std;

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	cout << "******************** ALGORITMO GULOSO *********************\n\n";
	
	int t; // declaração da variável t
	
	// cin - stream de entrada - realiza a leitura de uma sequência de dados
	cout << "----------------------- CONFIGURAÇÃO ----------------------" << "\nInsira o número de testes que deseja realizar: ";
	cin >> t; // pega a quantidade de testes que se deseja realizar e atribui a t
	
	// enquanto ainda houver testes
	while(t--)
	{
	    int n,k,i,l,j,mn=0,mx=0; //declaração de variáveis
	    
	    cout << "\n-------------------- DADOS DO PROBLEMA --------------------" << "\nInsira o número de tipos de doce: ";
	    cin >> n; // pega o número de tipos de doce e atribui a variável n
	    cout << "Insira o número máximo de doces que podem ser ganhos: ";
	    cin >> k; // pega o número máximo de doces que pode ser ganho e atribui a k
	    
	    int a[n]; // cria um array 'a'de tamanho 'n'
	    
	    for(i=0;i<n;i++){ // para cada item do array, ou seja, para cada doce
		    cout << "Insira o preço do doce " << i+1 << ": ";
		    cin>>a[i]; // insere o preço de cada um
		} 
	    sort(a,a+n); // ordena os elementos do array 'a'
	    
	    l=ceil((double)n/(double)(k+1)); // l = n/(k+1) com arredondamento para cima
	    
	    for(i=0;i<l;i++) // de i = 0 até l
	    {
	        mn+=a[i]; // o valor mn será igual ao valor atual + o valor a[i]
	    }
	    
	    j=n-1; // j é igual ao número de tipos de doce menos 1
	    while(l--) // enquanto l-- for verdadeiro
	    {
	        mx+=a[j]; // o valor mx será igual ao valor atual + o valor a[j]
	        j--; // decrementação de j
	    }
	    cout << "\n------------------------ RESULTADO ------------------------" << "\nQuantidade mínima de dinheiro necessária: ";
	    cout << mn; // imprime o valor minimo
		cout << "\nQuantidade máxima de dinheiro necessária: ";
		cout << mx << endl; // imprime o valor máximo
	    
	}
	return 0;
}
