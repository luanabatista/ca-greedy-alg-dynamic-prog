/* UNIVERSIDADE FEDERAL DO SUL E SUDESTE DO PAR�
   DISCIPLINA: COMPLEXIDADE DE ALGORITMOS
   PROFESSOR: MANOEL RIBEIRO
   ALUNOS: JOS� ARTHUR E LUANA BATISTA
   
   DEFINI��O DO PROBLEMA:
   Em uma loja de doces existem N tipos de doce e o cliente tem acesso

   Em uma loja de doces com N tipos de doce o cliente observa o pre�o 
   de cada um.
   Nela ocorre uma promo�a�o, na compra de de 1 doce voc� cada K 
   outros doces (de tipos diferentes) de gra�a.

   Agora voc� tem que responder duas perguntas. 
   1 - Qual a quantidade m�nima de dinheiro que voc� tem que gastar 
       para obter todos os N tipos de doce?
   2 - Qual a quantidade m�xima de dinheiro que voc� gastaria para 
       obter todos os N tipos de doce?

   Para os dois casos se aplica a condi��o da promo��o de que na compra 
   de 1 voc� ganha K doces.

   SOLU��O:
   O algoritmo a seguir � uma solu��o gulosa para o problema.

   RESTRI��ES:      
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
	
	int t; // declara��o da vari�vel t
	
	// cin - stream de entrada - realiza a leitura de uma sequ�ncia de dados
	cout << "----------------------- CONFIGURA��O ----------------------" << "\nInsira o n�mero de testes que deseja realizar: ";
	cin >> t; // pega a quantidade de testes que se deseja realizar e atribui a t
	
	// enquanto ainda houver testes
	while(t--)
	{
	    int n,k,i,l,j,mn=0,mx=0; //declara��o de vari�veis
	    
	    cout << "\n-------------------- DADOS DO PROBLEMA --------------------" << "\nInsira o n�mero de tipos de doce: ";
	    cin >> n; // pega o n�mero de tipos de doce e atribui a vari�vel n
	    cout << "Insira o n�mero m�ximo de doces que podem ser ganhos: ";
	    cin >> k; // pega o n�mero m�ximo de doces que pode ser ganho e atribui a k
	    
	    int a[n]; // cria um array 'a'de tamanho 'n'
	    
	    for(i=0;i<n;i++){ // para cada item do array, ou seja, para cada doce
		    cout << "Insira o pre�o do doce " << i+1 << ": ";
		    cin>>a[i]; // insere o pre�o de cada um
		} 
	    sort(a,a+n); // ordena os elementos do array 'a'
	    
	    l=ceil((double)n/(double)(k+1)); // l = n/(k+1) com arredondamento para cima
	    
	    for(i=0;i<l;i++) // de i = 0 at� l
	    {
	        mn+=a[i]; // o valor mn ser� igual ao valor atual + o valor a[i]
	    }
	    
	    j=n-1; // j � igual ao n�mero de tipos de doce menos 1
	    while(l--) // enquanto l-- for verdadeiro
	    {
	        mx+=a[j]; // o valor mx ser� igual ao valor atual + o valor a[j]
	        j--; // decrementa��o de j
	    }
	    cout << "\n------------------------ RESULTADO ------------------------" << "\nQuantidade m�nima de dinheiro necess�ria: ";
	    cout << mn; // imprime o valor minimo
		cout << "\nQuantidade m�xima de dinheiro necess�ria: ";
		cout << mx << endl; // imprime o valor m�ximo
	    
	}
	return 0;
}
